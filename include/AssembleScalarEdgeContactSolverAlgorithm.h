/*------------------------------------------------------------------------*/
/*  Nalu 1.0 Copyright 2014 Sandia Corporation.                           */
/*  This software is released under the BSD license detailed              */
/*  in the file, LICENSE which is located in the top-level Nalu           */
/*  directory structure                                                   */
/*------------------------------------------------------------------------*/


#ifndef AssembleScalarEdgeContactSolverAlgorithm_h
#define AssembleScalarEdgeContactSolverAlgorithm_h

#include<SolverAlgorithm.h>
#include<FieldTypeDef.h>

namespace stk {
namespace mesh {
class Part;
class FieldBase;
}
}

namespace sierra{
namespace nalu{

class Realm;

class AssembleScalarEdgeContactSolverAlgorithm : public SolverAlgorithm
{
public:

  AssembleScalarEdgeContactSolverAlgorithm(
    Realm &realm,
    stk::mesh::Part *part,
    EquationSystem *eqSystem,
    ScalarFieldType *scalarQ,
    VectorFieldType *dqdx,
    ScalarFieldType *diffFluxCoeff);
  virtual ~AssembleScalarEdgeContactSolverAlgorithm() {}
  virtual void initialize_connectivity();
  virtual void execute();
  
  double van_leer(
    const double &dqm,
    const double &dqp,
    const double &small);

  const bool meshMotion_;
    
  ScalarFieldType *scalarQ_;
  VectorFieldType *dqdx_;
  ScalarFieldType *diffFluxCoeff_;  
  VectorFieldType *meshVelocity_;
  VectorFieldType *velocity_;
  VectorFieldType *coordinates_;
  ScalarFieldType *density_;
  ScalarFieldType *haloMdot_;
  
  std::vector< const stk::mesh::FieldBase *> ghostFieldVec_;

};

} // namespace nalu
} // namespace Sierra

#endif
