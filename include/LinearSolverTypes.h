/*------------------------------------------------------------------------*/
/*  Nalu 1.0 Copyright 2014 Sandia Corporation.                           */
/*  This software is released under the BSD license detailed              */
/*  in the file, LICENSE which is located in the top-level Nalu           */
/*  directory structure                                                   */
/*------------------------------------------------------------------------*/


#ifndef LinearSolverTypes_h
#define LinearSolverTypes_h

#include <Tpetra_CrsGraph.hpp>
#include <Tpetra_CrsMatrix.hpp>

// Forward declare templates
namespace Teuchos {

template <typename T> 
class ArrayRCP;

template <typename T>
class MpiComm;

class ParameterList;

}

/*
 * This forward declaration is not needed and is wrong with the
 * recent changes to kokkos that moves the old kokkos names to the
 * kokkosclassic namespace.
namespace Kokkos {

class SerialNode;

}
*/

namespace Tpetra {

template <typename LocalOrdinal, typename GlobalOrdinal, typename Node>
class Map;

template <typename LocalOrdinal, typename GlobalOrdinal, typename Node >
class Export;

//template <typename LocalOrdinal, typename GlobalOrdinal, typename Node, typename LocalMatOpps>
//class CrsGraph;

template <typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
class MultiVector;

template <typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
class Vector;

//template <typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
//class CrsMatrix;

template <typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
class Operator;

}

namespace Belos {

template <typename Scalar, typename MultiVector>
class MultiVecTraits;

template <typename Scalar, typename MultiVector, typename Operator>
class OperatorTraits;

template <typename Scalar, typename MultiVector, typename Operator>
class LinearProblem;

template <typename Scalar, typename MultiVector, typename Operator>
class SolverManager;

template <typename Scalar, typename MultiVector, typename Operator>
class PseudoBlockGmresSolMgr;

template <typename Scalar, typename MultiVector, typename Operator>
class TFQMRSolMgr;

template <typename Scalar, typename MultiVector, typename Operator>
class PseudoBlockCGSolMgr;

}

namespace Ifpack2 {

template <typename Scalar, typename LocalOrdinal, typename GlobalOrdinal, typename Node>
class Preconditioner;

}

namespace sierra{
namespace nalu{

class TpetraLinearSolver;


struct LinSys {

typedef long   GlobalOrdinal; // MUST be signed
typedef int    LocalOrdinal;  // MUST be signed
typedef double Scalar;

typedef Kokkos::SerialNode                                                 Node;
typedef Teuchos::MpiComm<int>                                              Comm;
typedef Tpetra::Export< LocalOrdinal, GlobalOrdinal, Node >                Export;
typedef Tpetra::Import< LocalOrdinal, GlobalOrdinal, Node >                Import;
typedef Kokkos::DefaultKernels<void,LocalOrdinal,Node>::SparseOps          LocalMatOps;
typedef Tpetra::CrsGraph< LocalOrdinal, GlobalOrdinal, Node, LocalMatOps>  Graph;
typedef Tpetra::Map<LocalOrdinal,GlobalOrdinal,Node>                       Map;
typedef Tpetra::MultiVector<Scalar,LocalOrdinal,GlobalOrdinal,Node>        MultiVector;
typedef Teuchos::ArrayRCP<Scalar >                                         OneDVector;
typedef Teuchos::ArrayRCP<const Scalar >                                   ConstOneDVector;
typedef Tpetra::Vector<Scalar,LocalOrdinal,GlobalOrdinal,Node>             Vector;
typedef Tpetra::CrsMatrix<Scalar, LocalOrdinal, GlobalOrdinal, Node>       Matrix;
typedef Tpetra::Operator<Scalar, LocalOrdinal, GlobalOrdinal, Node>        Operator;
typedef Belos::MultiVecTraits<Scalar, MultiVector>                         MultiVectorTraits;
typedef Belos::OperatorTraits<Scalar,MultiVector, Operator>                OperatorTraits;
typedef Belos::LinearProblem<Scalar, MultiVector, Operator>                LinearProblem;
typedef Belos::SolverManager<Scalar, MultiVector, Operator>                SolverManager;
typedef Belos::PseudoBlockGmresSolMgr<Scalar, MultiVector, Operator>       GmresSolver;
typedef Belos::TFQMRSolMgr<Scalar, MultiVector, Operator>                  TfqmrSolver;
typedef Belos::PseudoBlockCGSolMgr<Scalar, MultiVector, Operator>          CgSolver;
typedef Ifpack2::Preconditioner<Scalar, LocalOrdinal, GlobalOrdinal, Node> Preconditioner;

};


} // namespace nalu
} // namespace Sierra

#endif
