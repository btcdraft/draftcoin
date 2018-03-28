// Copyright (c) 2010 Satoshi Nakamoteed

// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

unsigned int pnSeed[] =
{
0x7b0272a7, 0xada272a7
};

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xa2;
        pchMessageStart[1] = 0x7a;
        pchMessageStart[2] = 0xc1;
        pchMessageStart[3] = 0x7c;
        vAlertPubKey = ParseHex("046d4a82462704df06381163858c5998e85277d995967632348ecaa24668d48b7910bae9c427f6ae929907fc5a33b5d731dfb0e53a057a8200bc11eab87d693ef7");
        nDefaultPort = 20302;
        nRPCPort = 20304;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);


        const char* pszTimestamp = "2015 DraftCoin Start!";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
		CTransaction txNew(1, 1432374838, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1432374838;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 330954;

        hashGenesisBlock = genesis.GetHash();
/*
        while (hashGenesisBlock > bnProofOfWorkLimit.getuint256()){
            if (++genesis.nNonce==0) break;
            hashGenesisBlock = genesis.GetHash();
        }

        printf("%s\n MAIN ", hashGenesisBlock.ToString().c_str());
        printf("%s\n MAIN ", genesis.hashMerkleRoot.ToString().c_str());
        printf("%x\n MAIN ", bnProofOfWorkLimit.GetCompact());
        printf("%d\n MAIN ", genesis.nNonce);
*/

/*
Updated to support DNS masternode entries
*/
        assert(hashGenesisBlock == uint256("0x00000626d583465e39cc5eec2020f639792843efcfb4182d508e6734d4cfdab6"));
        assert(genesis.hashMerkleRoot == uint256("0x96b2046ee922b5724d19ade2ca7f44bc828e8b850f6e5416a98cf4fbea18ba87"));

		vSeeds.push_back(CDNSSeedData("node1.btcdraft.com", "node1.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node2.btcdraft.com", "node2.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node3.btcdraft.com", "node3.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node4.btcdraft.com", "node4.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node5.btcdraft.com", "node5.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node6.btcdraft.com", "node6.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node7.btcdraft.com", "node7.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node8.btcdraft.com", "node8.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node9.btcdraft.com", "node9.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node10.btcdraft.com", "node10.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node11.btcdraft.com", "node11.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node12.btcdraft.com", "node12.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node13.btcdraft.com", "node13.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node14.btcdraft.com", "node14.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node15.btcdraft.com", "node15.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node16.btcdraft.com", "node16.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node17.btcdraft.com", "node17.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node18.btcdraft.com", "node18.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node19.btcdraft.com", "node19.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node20.btcdraft.com", "node20.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node21.btcdraft.com", "node21.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node22.btcdraft.com", "node22.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node23.btcdraft.com", "node23.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node24.btcdraft.com", "node24.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node25.btcdraft.com", "node25.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node26.btcdraft.com", "node26.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node27.btcdraft.com", "node27.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node28.btcdraft.com", "node28.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node29.btcdraft.com", "node29.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node30.btcdraft.com", "node30.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node31.btcdraft.com", "node31.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node32.btcdraft.com", "node32.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node33.btcdraft.com", "node33.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node34.btcdraft.com", "node34.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node35.btcdraft.com", "node35.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node36.btcdraft.com", "node36.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node37.btcdraft.com", "node37.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node38.btcdraft.com", "node38.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node39.btcdraft.com", "node39.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node40.btcdraft.com", "node40.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node41.btcdraft.com", "node41.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node42.btcdraft.com", "node42.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node43.btcdraft.com", "node43.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node44.btcdraft.com", "node44.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node45.btcdraft.com", "node45.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node46.btcdraft.com", "node46.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node47.btcdraft.com", "node47.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node48.btcdraft.com", "node48.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node49.btcdraft.com", "node49.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node50.btcdraft.com", "node50.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node51.btcdraft.com", "node51.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node52.btcdraft.com", "node52.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node53.btcdraft.com", "node53.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node54.btcdraft.com", "node54.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node55.btcdraft.com", "node55.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node56.btcdraft.com", "node56.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node57.btcdraft.com", "node57.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node58.btcdraft.com", "node58.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node59.btcdraft.com", "node59.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node60.btcdraft.com", "node60.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node61.btcdraft.com", "node61.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node62.btcdraft.com", "node62.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node63.btcdraft.com", "node63.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node64.btcdraft.com", "node64.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node65.btcdraft.com", "node65.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node66.btcdraft.com", "node66.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node67.btcdraft.com", "node67.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node68.btcdraft.com", "node68.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node69.btcdraft.com", "node69.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node70.btcdraft.com", "node70.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node71.btcdraft.com", "node71.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node72.btcdraft.com", "node72.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node73.btcdraft.com", "node73.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node74.btcdraft.com", "node74.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node75.btcdraft.com", "node75.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node76.btcdraft.com", "node76.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node77.btcdraft.com", "node77.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node78.btcdraft.com", "node78.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node79.btcdraft.com", "node79.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node80.btcdraft.com", "node80.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node81.btcdraft.com", "node81.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node82.btcdraft.com", "node82.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node83.btcdraft.com", "node83.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node84.btcdraft.com", "node84.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node85.btcdraft.com", "node85.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node86.btcdraft.com", "node86.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node87.btcdraft.com", "node87.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node88.btcdraft.com", "node88.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node89.btcdraft.com", "node89.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node90.btcdraft.com", "node90.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node91.btcdraft.com", "node91.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node92.btcdraft.com", "node92.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node93.btcdraft.com", "node93.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node94.btcdraft.com", "node94.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node95.btcdraft.com", "node95.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node96.btcdraft.com", "node96.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node97.btcdraft.com", "node97.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node98.btcdraft.com", "node98.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node99.btcdraft.com", "node99.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node100.btcdraft.com", "node100.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node101.btcdraft.com", "node101.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node102.btcdraft.com", "node102.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node103.btcdraft.com", "node103.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node104.btcdraft.com", "node104.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node105.btcdraft.com", "node105.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node106.btcdraft.com", "node106.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node107.btcdraft.com", "node107.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node108.btcdraft.com", "node108.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node109.btcdraft.com", "node109.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node110.btcdraft.com", "node110.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node111.btcdraft.com", "node111.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node112.btcdraft.com", "node112.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node113.btcdraft.com", "node113.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node114.btcdraft.com", "node114.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node115.btcdraft.com", "node115.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node116.btcdraft.com", "node116.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node117.btcdraft.com", "node117.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node118.btcdraft.com", "node118.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node119.btcdraft.com", "node119.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node120.btcdraft.com", "node120.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node121.btcdraft.com", "node121.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node122.btcdraft.com", "node122.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node123.btcdraft.com", "node123.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node124.btcdraft.com", "node124.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("node125.btcdraft.com", "node125.btcdraft.com"));
		vSeeds.push_back(CDNSSeedData("dns.btcdraft.ca", "dns.btcdraft.ca"));
	    	vSeeds.push_back(CDNSSeedData("204.188.161.57", "204.188.161.57"));
		vSeeds.push_back(CDNSSeedData("149.56.101.219", "149.56.101.219"));
		vSeeds.push_back(CDNSSeedData("158.69.199.130", "158.69.199.130"));
	    	vSeeds.push_back(CDNSSeedData("204.188.161.61", "204.188.161.61"));
		vSeeds.push_back(CDNSSeedData("99.248.230.242", "99.248.230.242"));
	    	vSeeds.push_back(CDNSSeedData("68.206.29.192", "68.206.29.192"));
	    	vSeeds.push_back(CDNSSeedData("209.195.104.6", "209.195.104.6"));
/*
	Change to support Boost 1.6
        base58Prefixes[PUBKEY_ADDRESS] = list_of(30);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(91);
        base58Prefixes[SECRET_KEY] =     list_of(117);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x73)(0x77)(0xEE);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x73)(0xDD)(0x55);
  */      
	base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,30);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,91);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,117);
	base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0xc73)(0x77)(0xEE).convert_to_container<std::vector<unsigned char> >();
	base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0xc73)(0xDD)(0x55).convert_to_container<std::vector<unsigned char> >();

/*
Change to support Boost 1.6
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x73)(0x77)(0xEE);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x73)(0xDD)(0x55);
*/
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 15000;

		// Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xaa;
        pchMessageStart[1] = 0x33;
        pchMessageStart[2] = 0xff;
        pchMessageStart[3] = 0x77;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("0433ec1132f34b5d4cafe6e9b3d848b710d75d8ec7a363d24554eac5256e70e5850b33a716492f2570f6f0cc5b2d3c01c2dfb25bf0a9327e634dee8a3b2d1039bb");
        nDefaultPort = 12345;
        nRPCPort = 12346;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 81778;
        hashGenesisBlock = genesis.GetHash();
/*
        while (hashGenesisBlock > bnProofOfWorkLimit.getuint256()){
            if (++genesis.nNonce==0) break;
            hashGenesisBlock = genesis.GetHash();
        }

        printf("%s\n TESTNET ", hashGenesisBlock.ToString().c_str());
        printf("%s\n TESTNET ", genesis.hashMerkleRoot.ToString().c_str());
        printf("%x\n TESTNET ", bnProofOfWorkLimit.GetCompact());
        printf("%d\n TESTNET ", genesis.nNonce);
*/
        assert(hashGenesisBlock == uint256("0x00007fe66ae67c7d800791c56234ef019ca1f85f9b059fcccc49447d33c22481"));

        vFixedSeeds.clear();
        vSeeds.clear();

        /* 
	base58Prefixes[PUBKEY_ADDRESS] = list_of(110);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
        base58Prefixes[SECRET_KEY]     = list_of(239);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x17)(0xFF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x43)(0x99);
	*/
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,110);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x17)(0xFF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x43)(0x99).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xaf;
        pchMessageStart[1] = 0xbb;
        pchMessageStart[2] = 0x55;
        pchMessageStart[3] = 0xdd;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1412222222;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 8;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 47992;
        strDataDir = "regtest";
/*
        while (hashGenesisBlock > bnProofOfWorkLimit.getuint256()){
            if (++genesis.nNonce==0) break;
            hashGenesisBlock = genesis.GetHash();
        }

        printf("%s\n REGTEST ", hashGenesisBlock.ToString().c_str());
        printf("%s\n REGTEST ", genesis.hashMerkleRoot.ToString().c_str());
        printf("%x\n REGTEST ", bnProofOfWorkLimit.GetCompact());
        printf("%d\n REGTEST ", genesis.nNonce);
*/
        assert(hashGenesisBlock == uint256("0x21a8f72f07cec34eb88c6088f382eeb868c9813adfb9edffbe40a5e076c14cb8"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
