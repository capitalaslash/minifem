#pragma once

#include "def.hpp"
#include "geo.hpp"

template <typename RefElem>
uint constexpr numDOFs()
{
  return 1 * RefElem::dof_place[0] +
    RefElem::GeoElem_T::numFaces * RefElem::dof_place[1] +
    RefElem::GeoElem_T::numEdges * RefElem::dof_place[2] +
    RefElem::GeoElem_T::numPts * RefElem::dof_place[3];
}

struct RefLineP1
{
  typedef Line GeoElem_T;
  static GeoElem_T const geoElem;
  static uint constexpr dim = 1U;
  static uint constexpr numFuns = 2U;
  static std::array<uint,4> constexpr dof_place{0,0,0,1};
  static uint constexpr dofPerFacet = 1U;
  static std::array<std::array<uint,1>,2> constexpr dofOnFacet = {
    {{0}, {1}}
  };
  typedef Eigen::Vector2d LocalVec_T;
  typedef Eigen::Matrix2d LocalMat_T;

  static std::array<Vec3,numFuns> const points;
  static std::array<scalarFun_T,numFuns> const phiFun;
  static std::array<vectorFun_T,numFuns> const dphiFun;
  static LocalMat_T const massMat;
  static LocalMat_T const gradMat;
  static double constexpr volume = 2.L;

  static std::array<Vec3,numFuns> dofPts(GeoElem const & e)
  {
     std::array<Vec3,numFuns> dofPts =
     {
       e.pointList[0]->coord,
       e.pointList[1]->coord,
     };
     return std::move(dofPts);
  }
};

struct RefLineP2
{
  typedef Line GeoElem_T;
  static GeoElem_T const geoElem;
  static uint constexpr dim = 1U;
  static uint constexpr numFuns = 3U;
  static std::array<uint,4> constexpr dof_place{0,0,1,1};
  static uint constexpr dofPerFacet = 1U;
  static std::array<std::array<uint,1>,2> constexpr dofOnFacet = {
    {{0}, {1}}
  };
  typedef Eigen::Vector3d LocalVec_T;
  typedef Eigen::Matrix3d LocalMat_T;

  static std::array<Vec3,numFuns> const points;
  static std::array<scalarFun_T,numFuns> const phiFun;
  static std::array<vectorFun_T,numFuns> const dphiFun;
  static LocalMat_T const massMat;
  static LocalMat_T const gradMat;
  static double constexpr volume = 2.L;

  static std::array<Vec3,numFuns> dofPts(GeoElem const & e)
  {
     std::array<Vec3,numFuns> dofPts =
     {
       e.pointList[0]->coord,
       e.pointList[1]->coord,
       e.midpoint()
     };
     return std::move(dofPts);
  }
};

struct RefTriangleP1
{
  typedef Triangle GeoElem_T;
  static GeoElem_T const geoElem;
  static uint constexpr dim = 2U;
  static uint constexpr numFuns = 3U;
  static std::array<uint,4> constexpr dof_place{0,0,0,1};
  static uint constexpr dofPerFacet = 2U;
  static std::array<std::array<uint,2>,3> constexpr dofOnFacet = {
    {{0,1}, {1,2}, {2,0}}
  };
  typedef Eigen::Matrix<double,numFuns,1> LocalVec_T;
  typedef Eigen::Matrix<double,numFuns,numFuns> LocalMat_T;

  static std::array<scalarFun_T,numFuns> const phiFun;
  static std::array<vectorFun_T,numFuns> const dphiFun;
  static double constexpr volume = 0.5L;

  static std::array<Vec3,numFuns> dofPts(GeoElem const & e)
  {
     std::array<Vec3,numFuns> dofPts =
     {
       e.pointList[0]->coord,
       e.pointList[1]->coord,
       e.pointList[2]->coord
     };
     return std::move(dofPts);
  }
};

struct RefTriangleP2
{
  typedef Triangle GeoElem_T;
  static GeoElem_T const geoElem;
  static uint constexpr dim = 2U;
  static uint constexpr numFuns = 6U;
  static std::array<uint,4> constexpr dof_place{0,0,1,1};
  static uint constexpr dofPerFacet = 3U;
  static std::array<std::array<uint,3>,3> constexpr dofOnFacet = {
    {{0,1,3}, {1,2,4}, {2,0,5}}
  };
  typedef Eigen::Matrix<double,numFuns,1> LocalVec_T;
  typedef Eigen::Matrix<double,numFuns,numFuns> LocalMat_T;

  static std::array<scalarFun_T,numFuns> const phiFun;
  static std::array<vectorFun_T,numFuns> const dphiFun;
  static double constexpr volume = 0.5L;

  static std::array<Vec3,numFuns> dofPts(GeoElem const & e)
  {
     std::array<Vec3,numFuns> dofPts =
     {
       e.pointList[0]->coord,
       e.pointList[1]->coord,
       e.pointList[2]->coord,
       0.5*(e.pointList[0]->coord+e.pointList[1]->coord),
       0.5*(e.pointList[1]->coord+e.pointList[2]->coord),
       0.5*(e.pointList[2]->coord+e.pointList[0]->coord)
     };
     return std::move(dofPts);
  }
};

struct RefQuadQ1
{
  typedef Quad GeoElem_T;
  static GeoElem_T const geoElem;
  static uint constexpr dim = 2U;
  static uint constexpr numFuns = 4U;
  static std::array<uint,4> constexpr dof_place{0,0,0,1};
  static uint constexpr dofPerFacet = 2U;
  static std::array<std::array<uint,2>,4> constexpr dofOnFacet = {
    {{0,1}, {1,2}, {2,3}, {3,0}}
  };
  typedef Eigen::Matrix<double,numFuns,1> LocalVec_T;
  typedef Eigen::Matrix<double,numFuns,numFuns> LocalMat_T;

  static std::array<scalarFun_T,numFuns> const phiFun;
  static std::array<vectorFun_T,numFuns> const dphiFun;
  static double constexpr volume = 4.L;

  static std::array<Vec3,numFuns> dofPts(GeoElem const & e)
  {
     std::array<Vec3,numFuns> dofPts =
     {
       e.pointList[0]->coord,
       e.pointList[1]->coord,
       e.pointList[2]->coord,
       e.pointList[3]->coord
     };
     return std::move(dofPts);
  }
};

struct RefQuadQ2
{
  typedef Quad GeoElem_T;
  static GeoElem_T const geoElem;
  static uint constexpr dim = 2U;
  static uint constexpr numFuns = 9U;
  static std::array<uint,4> constexpr dof_place{0,1,1,1};
  static uint constexpr dofPerFacet = 3U;
  static std::array<std::array<uint,3>,4> constexpr dofOnFacet = {
    {{0,1,4}, {1,2,5}, {2,3,6}, {3,0,7}}
  };
  typedef Eigen::Matrix<double,numFuns,1> LocalVec_T;
  typedef Eigen::Matrix<double,numFuns,numFuns> LocalMat_T;

  static std::array<scalarFun_T,numFuns> const phiFun;
  static std::array<vectorFun_T,numFuns> const dphiFun;
  static double constexpr volume = 4.L;

  static std::array<Vec3,numFuns> dofPts(GeoElem const & e)
  {
     std::array<Vec3,numFuns> dofPts =
     {
       e.pointList[0]->coord,
       e.pointList[1]->coord,
       e.pointList[2]->coord,
       e.pointList[3]->coord,
       0.5*(e.pointList[0]->coord+e.pointList[1]->coord),
       0.5*(e.pointList[1]->coord+e.pointList[2]->coord),
       0.5*(e.pointList[2]->coord+e.pointList[3]->coord),
       0.5*(e.pointList[3]->coord+e.pointList[0]->coord),
       e.midpoint()
     };
     return std::move(dofPts);
  }
};
