/**
 *  Copyright (C) 2021 FISCO BCOS.
 *  SPDX-License-Identifier: Apache-2.0
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @brief Validator for the consensus module
 * @file Validator.h
 * @author: yujiechen
 * @date 2021-04-21
 */
#pragma once
#include "bcos-framework/interfaces/txpool/TxPoolInterface.h"
#include "framework/ValidatorInterface.h"

namespace bcos
{
namespace consensus
{
class Validator : public ValidatorInterface
{
public:
    using Ptr = std::shared_ptr<Validator>;
    explicit Validator(bcos::txpool::TxPoolInterface::Ptr _txPool) : m_txPool(_txPool) {}
    ~Validator() override {}

    virtual void registerVerifyFinishedHandler(
        std::function<void(Error::Ptr, bool)> _verifyFinishedHandler)
    {
        m_verifyFinishedHandler = _verifyFinishedHandler;
    }

    void verifyProposal(
        bcos::crypto::PublicPtr _fromNode, ProposalInterface::Ptr _proposal) override
    {
        m_txPool->asyncVerifyBlock(_fromNode, _proposal->data(), m_verifyFinishedHandler);
    }

protected:
    bcos::txpool::TxPoolInterface::Ptr m_txPool;
    std::function<void(Error::Ptr, bool)> m_verifyFinishedHandler;
};
}  // namespace consensus
}  // namespace bcos