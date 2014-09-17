/*------------------------------------------------------------------------*/
/*  Nalu 1.0 Copyright 2014 Sandia Corporation.                           */
/*  This software is released under the BSD license detailed              */
/*  in the file, LICENSE which is located in the top-level Nalu           */
/*  directory structure                                                   */
/*------------------------------------------------------------------------*/


#ifndef Enums_h
#define Enums_h

#include <string>

namespace sierra {
namespace nalu {

enum AlgorithmType{
  INTERIOR  = 0,
  INFLOW    = 1,
  WALL      = 2,
  OPEN      = 3,
  MASS      = 4,
  SRC       = 5,
  CONTACT   = 6,
  SYMMETRY  = 7
};

enum BoundaryConditionType{
  INFLOW_BC    = 1,
  OPEN_BC      = 2,
  WALL_BC      = 3,
  CONTACT_BC   = 4,
  SYMMETRY_BC  = 5,
  PERIODIC_BC  = 6
};

enum EquationType {
  EQ_MOMENTUM = 0,
  EQ_CONTINUITY = 1,
  EQ_MIXTURE_FRACTION = 2,
  EQ_TURBULENT_KE = 3,
  EQ_TEMPERATURE = 4,
  EQ_INTENSITY = 5,
  EQ_ENTHALPY = 6,
  EQ_MESH_DISPLACEMENT = 7,
  EQ_SPEC_DISS_RATE = 8,
  EquationSystemType_END
};

static const std::string EquationTypeMap[] = {
  "Momentum",
  "Continuity",
  "Mixture_Fraction",
  "Turbulent_KE",
  "Temperature",
  "Intensity",
  "Enthalpy",
  "MeshVelocity",
  "Specific_Dissipation_Rate"
};

enum UserDataType {
  CONSTANT_UD = 0,
  FUNCTION_UD = 1,
  USER_SUB_UD = 2,
  UserDataType_END
};

// prop enum and name below
enum PropertyIdentifier {
  DENSITY_ID = 0,
  VISCOSITY_ID = 1,
  SPEC_HEAT_ID = 2,
  THERMAL_COND_ID = 3,
  ABSORBTION_COEFF_ID = 4,
  ENTHALPY_ID = 5,
  LAME_MU_ID = 6,
  LAME_LAMBDA_ID = 7,
  SCATTERING_COEFF_ID = 8,
  PropertyIdentifier_END
};

static const std::string PropertyIdentifierNames[] = {
  "density",
  "viscosity",
  "specific_heat",
  "thermal_conductivity",
  "absorption_coefficient",
  "enthalpy",
  "lame_mu",
  "lame_lambda",
  "scattering_coefficient"};

// prop enum and name below
enum  MaterialPropertyType {
  CONSTANT_MAT = 0,
  MIXFRAC_MAT = 1,
  POLYNOMIAL_MAT = 2,
  IDEAL_GAS_T_MAT = 3,
  GEOMETRIC_MAT = 4,
  IDEAL_GAS_T_P_MAT = 5,
  TABLE_MAT = 6,
  MaterialPropertyType_END
};

enum NaluState {
  NALU_STATE_N = 0,
  NALU_STATE_NM1 = 1
};

enum TurbulenceModel {
  LAMINAR = 0,
  KSGS = 1,
  SMAGORINSKY = 2,
  WALE = 3,
  SST = 4,
  SST_DES = 5,
  TurbulenceModel_END
};  

// matching string name index into above enums (must match PERFECTLY)
static const std::string TurbulenceModelNames[] = {
  "laminar",
  "ksgs",
  "smagorinsky",
  "wale",
  "sst",
  "sst_des"};

enum TurbulenceModelConstant {
  TM_cMu = 0,
  TM_kappa = 1,
  TM_cDESke = 2,
  TM_cDESkw = 3,
  TM_tkeProdLimitRatio = 4,
  TM_cmuEps = 5,
  TM_cEps = 6,
  TM_betaStar = 7,
  TM_aOne = 8,
  TM_betaOne = 9,
  TM_betaTwo = 10,
  TM_gammaOne = 11,
  TM_gammaTwo = 12,
  TM_sigmaKOne = 13,
  TM_sigmaKTwo = 14,
  TM_sigmaWOne = 15,
  TM_sigmaWTwo = 16,
  TM_cmuCs = 17,
  TM_Cw = 18,
  TM_END = 19
};

static const std::string TurbulenceModelConstantNames[] = {
  "cMu",
  "kappa",
  "cDESke",
  "cDESkw",
  "tkeProdLimitRatio",
  "cmuEps",
  "cEps",
  "betaStar",
  "aOne",
  "betaOne",
  "betaTwo",
  "gammaOne",
  "gammaTwo",
  "sigmaKOne",
  "sigmaKTwo",
  "sigmaWOne",
  "sigmaWTwo",
  "cmuCs",
  "Cw",
  "END"};

} // namespace nalu
} // namespace Sierra

#endif
