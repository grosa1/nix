// Copyright (c) 2013, German Neuroinformatics Node (G-Node)
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted under the terms of the BSD License. See
// LICENSE file in the root of the Project.

#ifndef NIX_FEATURE_HDF5_H
#define NIX_FEATURE_HDF5_H

#include <string>
#include <vector>

#include <nix/base/IBlock.hpp>
#include <nix/base/IFeature.hpp>
#include <nix/hdf5/EntityHDF5.hpp>

namespace nix {
namespace hdf5 {


/**
 * Converts a LinkType into a string.
 *
 * @param link_type   The type to convert.
 */
std::string linkTypeToString(LinkType link_type);

/**
 * Create a link type from a string. If no matching type
 * exists, an exception will be thrown.
 *
 * @return The link type that matches the string.
 */
LinkType linkTypeFromString(const std::string &str);


/**
 * Class that represents a NIX feature entity
 */
class FeatureHDF5 : virtual public base::IFeature, public EntityHDF5 {

private:

    std::shared_ptr<base::IBlock> block;

public:


    FeatureHDF5(const FeatureHDF5 &feature);


    FeatureHDF5(std::shared_ptr<base::IFile> file, std::shared_ptr<base::IBlock> block, const Group &group,
                const std::string &id, DataArray data, LinkType link_type);


    FeatureHDF5(std::shared_ptr<base::IFile> file, std::shared_ptr<base::IBlock> block, const Group &group,
                const std::string &id, DataArray data, LinkType link_type, time_t time);


    void linkType(LinkType type);


    LinkType linkType() const;


    void data(const std::string &data_array_id);


    std::shared_ptr<base::IDataArray> data() const;


    virtual ~FeatureHDF5();

};


} // namespace hdf5
} // namespace nix

#endif // NIX_FEATURE_HDF5_H
