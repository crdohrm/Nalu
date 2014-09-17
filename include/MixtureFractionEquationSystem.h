/*------------------------------------------------------------------------*/
/*  Nalu 1.0 Copyright 2014 Sandia Corporation.                           */
/*  This software is released under the BSD license detailed              */
/*  in the file, LICENSE which is located in the top-level Nalu           */
/*  directory structure                                                   */
/*------------------------------------------------------------------------*/


#ifndef MixtureFractionEquationSystem_h
#define MixtureFractionEquationSystem_h

#include <EquationSystem.h>
#include <FieldTypeDef.h>
#include <NaluParsing.h>

namespace stk{
struct topology;
}

namespace sierra{
namespace nalu{

class AlgorithmDriver;
class Realm;
class AssembleNodalGradAlgorithmDriver;
class LinearSystem;
class EquationSystems;


class MixtureFractionEquationSystem : public EquationSystem {

public:

  MixtureFractionEquationSystem(
    EquationSystems& equationSystems,
    const bool burkeSchumann);
  virtual ~MixtureFractionEquationSystem();

  void populate_derived_quantities();
  
  virtual void register_nodal_fields(
    stk::mesh::Part *part);

  void register_interior_algorithm(
    stk::mesh::Part *part);
  
  void register_inflow_bc(
    stk::mesh::Part *part,
    const stk::topology &theTopo,
    const InflowBoundaryConditionData &inflowBCData);
  
  void register_open_bc(
    stk::mesh::Part *part,
    const stk::topology &theTopo,
    const OpenBoundaryConditionData &openBCData);

  void register_wall_bc(
    stk::mesh::Part *part,
    const stk::topology &theTopo,
    const WallBoundaryConditionData &wallBCData);

  void register_contact_bc(
    stk::mesh::Part *part,
    const stk::topology &theTopo,
    const ContactBoundaryConditionData &contactBCData);

  virtual void register_symmetry_bc(
    stk::mesh::Part *part,
    const stk::topology &theTopo,
    const SymmetryBoundaryConditionData &symmetryBCData);

  void initialize();
  void reinitialize_linear_system();
  
  void predict_state();
  
  void solve_and_update();
  void update_and_clip();
  void compute_scalar_var_diss();
  void post_iter_work();

  const bool burkeSchumann_;

  ScalarFieldType *mixFrac_;
  VectorFieldType *dzdx_;
  ScalarFieldType *zTmp_;
  ScalarFieldType *visc_;
  ScalarFieldType *tvisc_;
  ScalarFieldType *evisc_;
  ScalarFieldType *scalarVar_;
  ScalarFieldType *scalarDiss_;
  
  AssembleNodalGradAlgorithmDriver *assembleNodalGradAlgDriver_;
  AlgorithmDriver *diffFluxCoeffAlgDriver_;
  AlgorithmDriver *speciesAlgDriver_;

  bool isInit_;
  
};


} // namespace nalu
} // namespace Sierra

#endif
