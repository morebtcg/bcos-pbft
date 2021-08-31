hunter_config(bcos-framework VERSION 3.0.0-local
    URL https://${URL_BASE}/FISCO-BCOS/bcos-framework/archive/d8f6a1399e27ab2ec15fd65644ed812bd1ca5c9c.tar.gz
    SHA1 56f381cce3dc5a88741a7f452b5f86addbe6b310
    CMAKE_ARGS HUNTER_PACKAGE_LOG_BUILD=ON HUNTER_PACKAGE_LOG_INSTALL=ON #DEBUG=ON
)

hunter_config(wedpr-crypto VERSION 1.1.0-10f314de
	URL https://${URL_BASE}/WeBankBlockchain/WeDPR-Lab-Crypto/archive/10f314de45ec31ce9e330922b522ce173662ed33.tar.gz
	SHA1 626df59f87ea2c6bb5128f7d104588179809910b
	CMAKE_ARGS HUNTER_PACKAGE_LOG_BUILD=OFF HUNTER_PACKAGE_LOG_INSTALL=ON
)