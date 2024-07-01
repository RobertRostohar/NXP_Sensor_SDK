/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __TEST_ECDOUBLEMUL521_H
#define __TEST_ECDOUBLEMUL521_H

#include <stdint.h>

uint32_t test_ecddoublemul_base521[2][2 * 18] = {
    {0xC2E5BD66, 0xF97E7E31, 0x856A429B, 0x3348B3C1, 0xA2FFA8DE, 0xFE1DC127, 0xEFE75928, 0xA14B5E77, 0x6B4D3DBA,
     0xF828AF60, 0x53FB521,  0x9C648139, 0x2395B442, 0x9E3ECB66, 0x404E9CD,  0x858E06B7, 0xC6,       0,
     0x9FD16650, 0x88BE9476, 0xA272C240, 0x353C7086, 0x3FAD0761, 0xC550B901, 0x5EF42640, 0x97EE7299, 0x273E662C,
     0x17AFBD17, 0x579B4468, 0x98F54449, 0x2C7D1BD9, 0x5C8A5FB4, 0x9A3BC004, 0x39296A78, 0x118,      0},
    {0xC5F3E5E5, 0x16D1386F, 0xA7764E20, 0x20D6A284, 0x353185B8, 0x92D74A69, 0x76CB0C63, 0xDABC2D94, 0x10ABA5A8,
     0xF336B2D8, 0x3CB463E9, 0x7C778B22, 0x1C897AB1, 0x7B3974F2, 0x322E56D3, 0x20F08E15, 0x37,       0,
     0x46AC95B9, 0xA3FB979F, 0x93383C05, 0x35717ECF, 0x689A430D, 0x9A9D08FE, 0xD5BDB9A1, 0x23AFE74F, 0x9DEE4B52,
     0xB7CC0B64, 0xC54AA5C0, 0xD396971F, 0x2ED77AD4, 0x4657E2F5, 0x27207E12, 0x30914EAD, 0x13B,      0}};
uint32_t test_ecddoublemul_scalars521[9][2 * 18] = {
    {0x7FECC67D, 0x3996B2A3, 0x87D9533A, 0x9BFDA204, 0xE29F4FA6, 0x71FF8FA0, 0x39802606, 0xE9EB606B, 0x89E704D4,
     0x64B748DA, 0x60AC2B93, 0x5D47A85D, 0x4D1CAEBD, 0x865D9B21, 0x55DE53A8, 0x1876052F, 0xF2,       0,
     0x3C332492, 0x823A3370, 0x2CE63716, 0x4A16DCD7, 0xED380DF3, 0xA8662D0A, 0x99BA3A93, 0xAECF97DA, 0x7CB6795E,
     0x2652F963, 0xE7D42438, 0x55B8A0B5, 0xAF5EF20F, 0x7BF3C359, 0xD37A7887, 0x363B80B7, 0x73,       0},
    {0x641D1056, 0x275A7C50, 0x60E66E2E, 0xE98B888B, 0xA74074E2, 0x6375B670, 0x39081DEA, 0xEC533E5C, 0x74B4572D,
     0x45ED6C72, 0xC08838AA, 0xE1143C39, 0x6FA0E491, 0xFFE2DB45, 0x5ABB18DB, 0x3762A3A2, 0x1D6,      0,
     0x337B5BA9, 0xC44FD6CD, 0x9C37DC25, 0x1331C2FB, 0xB5C232FC, 0xFA49ED6A, 0x3A362012, 0x4A44A1D8, 0x5C7C964F,
     0x2BCCAD15, 0x9AB7135E, 0xE4E9B0EF, 0xEB66519C, 0x56562EF8, 0xABAE70D0, 0x3F272299, 0x1FE,      0},
    {0xCE3261A2, 0x82248799, 0xD12EC8ED, 0xB529560C, 0x1EF84F71, 0xCA8824ED, 0x8B22190B, 0xE367017C, 0x9DCD90F9,
     0x5AA0DD93, 0xAF57ACB4, 0x23A4EFEF, 0x68A7529C, 0xAEBB7EC1, 0xCB2393A8, 0xF8310E91, 0x1F7,      0,
     0x277EA0B3, 0xDFA1A4DE, 0x95852AC,  0xEDE64D47, 0x5E8F2ECD, 0xCC3F3103, 0x79997583, 0x6BFFAABE, 0xD012087A,
     0x683E6FF,  0xEA5A40E4, 0xC2B09221, 0x37D9EC79, 0x1C11E13E, 0xDC09C37D, 0xA143AAE6, 0x141,      0},
    {0xE85BA250, 0xB21F7B9B, 0xF6C5B0A3, 0xD7402818, 0xF73ED434, 0x36F0CEA7, 0xDE281475, 0x2821099C, 0x556D1152,
     0x63762D9E, 0x3AE3EDDA, 0xC81EA4D9, 0x73E08C03, 0x2110CED0, 0xB88A4D35, 0x4D30029A, 0x155,      0,
     0xBFC19F9D, 0xE0EC7AF5, 0x860AF670, 0x625E70DB, 0x9C2380AA, 0x1DD617BD, 0x3DE2D3D6, 0xE8C80AAD, 0x2047A60,
     0xB1CDEB1E, 0xF8E3187A, 0xB64E7B6A, 0x504C8B5F, 0x361A96A1, 0xB3EDC662, 0x539DF586, 0x19B,      0},
    {0x82611795, 0x6F53058,  0xB8F8D9CF, 0xE634698,  0x45963DF2, 0x4C597D40, 0x20BF6490, 0xF8922791, 0xD1F76C1C,
     0x59034D6B, 0xB36A5CFC, 0xC11A087B, 0x7063F5BA, 0x2A16FAE3, 0xF4103C9C, 0x30FE7463, 0x1B0,      0,
     0x91EF702B, 0xF93F0709, 0xC80F92B3, 0x4D2A6053, 0x6E626F0E, 0x4F69B8A0, 0x754CEAC1, 0x13F17163, 0xBABE89FC,
     0x1F84E91E, 0xD2813758, 0x889A6F10, 0xA8A11527, 0x9FFA185D, 0x94D43239, 0xE7211F6E, 0x13A,      0},
    {0xF2AA8ACC, 0x574569D,  0x7FAFAFA0, 0x5CD6A6C7, 0xD4125C8B, 0x5C5DB4DF, 0x7B073ADC, 0xBE19458F, 0xC2142C3E,
     0xEC6038C2, 0xF4E55D67, 0x7C73893B, 0x32222B20, 0x2932D07E, 0x80221560, 0xDA3A248B, 0x17,       0,
     0xD331BFDF, 0x4CD296BC, 0x779E8BB,  0xC4F8D7C3, 0xB29D530D, 0x13A790F9, 0x47FB99E,  0x561F39CE, 0x20614DD6,
     0x131FA26C, 0x3FA207DD, 0x8CFA70A0, 0x89076F5E, 0xC8F7EBDF, 0x16E89116, 0x26991DA5, 0x3B,       0},
    {0x1DA75B5,  0x17FD2109, 0x43E01036, 0xE0B4AEF9, 0x676C6113, 0xCD67F16E, 0x484283C4, 0x3C31325B, 0xB67F9BEA,
     0x65BA4E92, 0x9C2B06E8, 0x94A25A58, 0x871DE657, 0xFA537182, 0xBE8DDC0A, 0x36D048CE, 0xB8,       0,
     0x94920C77, 0xA1984343, 0x9F113370, 0x9DA465B0, 0x867A6E68, 0x4DC15920, 0x620744D1, 0x8EE576BA, 0xA9D46EF4,
     0xD379E336, 0x3727DB8,  0xAB5CFBB4, 0x39582E94, 0x18089F31, 0xC1BCBC35, 0xDD80F090, 0x166,      0},
    {0x215191AF, 0xD66EDF38, 0x369BBA16, 0x1784EDB2, 0x916E72C6, 0x56F3B8B5, 0x70AB3530, 0xB4E93603, 0xC20C47E6,
     0x9B18C53E, 0x844646C6, 0xC01697BD, 0x2CC3B5B3, 0x7EEC0292, 0x39A93BB4, 0x600FB744, 0x10,       0,
     0x90979C9,  0x8FBDD709, 0x7A88B863, 0x4040688C, 0xB8C2C0FD, 0xBF1B7857, 0xAF5B24ED, 0x4C92C054, 0xCB642D40,
     0xCC7FE182, 0xAD1BA235, 0xD965EADB, 0x6666AB8,  0xFAE5AB0E, 0x6A5FDB38, 0x1D2AE021, 0x19,       0},
    {0x25C812A5, 0x51EA645E, 0x7A3B3F0D, 0x7044D515, 0xA6409DF,  0xC23C7AFD, 0xA2DAC808, 0x367B2025, 0x7E7C9CB4,
     0x66C6CD1D, 0x3C74A757, 0xC6AA31D9, 0x2D084309, 0xA2A5565C, 0x7F1571A0, 0x3D3A608E, 0x3D,       0,
     0x6B9463DD, 0x909089E5, 0x4D48CF91, 0xE348936,  0x1A9882BE, 0xFF562DF5, 0x2E1C34E6, 0x5CC69E89, 0xEC03E5BF,
     0x8D2732E6, 0x731A4CEE, 0x3C2555E7, 0xEC68E41,  0x4906B182, 0x11435B74, 0x149A01B8, 0x16,       0}};
uint32_t test_ecddoublemul_result521[9][2 * 18] = {
    {0x8CFBFE89, 0x74522C22, 0x3F34F3A2, 0xDD4781B1, 0x22A651C1, 0xED9CF18E, 0x56A5A503, 0x56AC80CA, 0x14DDA80A,
     0x6E8477F4, 0x2550EA60, 0xCAAAEA67, 0x2DDAED39, 0xF30E180,  0xB85E19B6, 0x9D1505AC, 0x7C,       0,
     0x8948DFA3, 0xE9B3F1F9, 0x19F6CD46, 0xB0969CDD, 0xA22103E9, 0x4D9A415E, 0xD9AC349C, 0x9EB57CBC, 0x1BCA1F1F,
     0xCE2094A1, 0x231BA977, 0x70F449BA, 0xE2102156, 0x8620B68E, 0xA131ECAC, 0x1D4DD24,  0x52,       0},
    {0xA6D3BD20, 0x5EB70E06, 0xFC4F3C7,  0x2E8C6CA0, 0x8086ECA5, 0xD4A1A98F, 0x22C0658,  0x6319869A, 0x437865C8,
     0xFC92AD3A, 0x2E749888, 0x1D45DE8C, 0x46788672, 0x14AF04B0, 0xBDB7CDA2, 0x68972851, 0x124,      0,
     0x3C513DF1, 0x7E16DC48, 0xC023991F, 0xBF358B79, 0x6AEB6912, 0x54CFC350, 0x96E6AC0E, 0x81F5D6DA, 0x683434C,
     0xD3119EA1, 0xD35819F1, 0xD8E9E564, 0x435D5E76, 0xCE831BB2, 0x5A43C03A, 0xF4D338E3, 0x62,       0},
    {0xD417ACF6, 0x7B04CC2A, 0xF5E99ED5, 0xEFCA054E, 0xD7175AA2, 0x1A6AA697, 0xC0947A85, 0xFF57EC60, 0xCA1D0CA6,
     0x33D3C36A, 0x39DB107A, 0xCE928BAD, 0xFC49C98A, 0x453F8DA,  0xAF407CCA, 0xEB9BC8F3, 0x5F,       0,
     0xE2720339, 0xBD1AB950, 0xB2E2DB3C, 0x540991E,  0xDEFDCD95, 0xB77AE3F6, 0xB5CD0FB0, 0x6A81E54,  0x767C9D6E,
     0xF17E16BC, 0x7DEAEE3,  0x6512301E, 0x7068D6E1, 0x4C725875, 0x4D992516, 0xE9503563, 0x19,       0},
    {0x22E773D7, 0x16F7DB9,  0x266F62D,  0x622B4596, 0xE52AF043, 0x9E2F7B29, 0xF8C3C1E2, 0x657BA1F7, 0xDF37C670,
     0xBFD37A55, 0xE5029542, 0x77E6CC27, 0x3AE39B50, 0xD501551D, 0xC59EC0B3, 0x6833CCA8, 0x4A,       0,
     0x692AE195, 0xD6D6BD7F, 0x3323C077, 0xE997D4BA, 0xB472A596, 0x5385E6D7, 0x2565CB8E, 0x2AF5CFC2, 0x26F5961F,
     0x23F19AF0, 0xB7CDBD2B, 0xE028937D, 0x45127E9B, 0xC9232475, 0xEBC7D9FD, 0xF81EC178, 0xA4,       0},
    {0xABAF0F93, 0x991206DE, 0x2EA652F4, 0x60E5DBF1, 0xF4CD3CED, 0x4448FD2B, 0xB1294FF6, 0x91A909B4, 0xCD128942,
     0x2A90ABAC, 0xA8A7ADF5, 0xC33A1C69, 0x403CDFB8, 0x2A8E8C3E, 0x367C7F33, 0x9CA97534, 0x11B,      0,
     0x81AD03A3, 0x7D7765B8, 0xFCD8951B, 0xFD9C8D65, 0x3A94E4F,  0x2E14E8E0, 0xDA5A8A95, 0xDFF2AF62, 0x565B59EC,
     0x6236C9F4, 0x5938F9FC, 0x1C50F43F, 0x6DE2D827, 0x74C2D28,  0xE1273BF1, 0x3A882263, 0x1F,       0},
    {0x3561CDC4, 0x5BEC00FA, 0x997CAE2,  0x608C7BF8, 0xE78260D8, 0xA3A3A458, 0x61EA7401, 0xDECB13BD, 0xC640DC74,
     0x1DEF310A, 0x1B7299D7, 0xF2A6023A, 0x3C18F953, 0x2A5C4E10, 0x9C3AE6E,  0x2844FDBE, 0x98,       0,
     0x52A9E92B, 0xF9812AD9, 0xA2F609C8, 0x9C2B17D3, 0x146028E1, 0xA52FF623, 0x3E0A55F5, 0xFB0F355E, 0x4BAE9605,
     0xFAFD72D9, 0x29687B8C, 0x5C879DEB, 0xD9EF3256, 0x59C89E33, 0x6AD472D3, 0xB6B8AFB1, 0x198,      0},
    {0xFA7F0435, 0xFD64B7DD, 0x5FD3DAE5, 0x6E755A03, 0x8A5507ED, 0x55C5B81A, 0x4E973CC1, 0x64EEE6ED, 0xA4543288,
     0xF11BCB9D, 0x87F9E3EB, 0x5E744575, 0x2EA0D6EF, 0x152BB2A0, 0x818CA517, 0xBA4F8223, 0x63,       0,
     0x492B33A6, 0x6B94B43B, 0xDCAFCFC2, 0x68242C58, 0x41938F33, 0x5E995C54, 0x6A49CAB1, 0xA7A8DF3A, 0xA17CA8C1,
     0x4B47D9C0, 0xB252A2CB, 0xAA250853, 0xC4DC7D98, 0xEE59CBD2, 0xA3C5A4E4, 0x492B8149, 0x1E2,      0},
    {0xAF276D51, 0xBFAE1A67, 0x33510D60, 0x8090E464, 0xF172EF1E, 0xEBECD652, 0x6F30B8D3, 0x79D9EFE8, 0x25E6F107,
     0x7DBC1399, 0x8EA34F86, 0x1014B230, 0x31818046, 0xB8A19687, 0x476D44AD, 0x745DB517, 0xC1,       0,
     0x7356821A, 0x1510E605, 0x591973A5, 0xB2C597A5, 0xDB2A65C2, 0xA4800E25, 0x397D8594, 0xE77BD45E, 0x7BB2D401,
     0x59251B8F, 0xCEC19A59, 0xE156B57C, 0x584324F3, 0x5BE4BCD1, 0x22041BE0, 0x1A1C877D, 0x8,        0},
    {0xC70FFB5D, 0x3C5DDE80, 0xBA074D14, 0x463C84FC, 0x32EC85A0, 0xF1833D7B, 0xD35B3C8E, 0xB8018383, 0x47000F30,
     0x256E77D1, 0x7AAC3728, 0x3CD19413, 0x4A0E061F, 0x8E76051,  0x10C20470, 0x9ECEBFC,  0xFD,       0,
     0xCAED6B53, 0x86D79A67, 0x4C0AFB64, 0xB676BB89, 0x9130FCB5, 0xB6CBF042, 0x891F02D1, 0x5A009780, 0x63E2BCF,
     0xE5173434, 0x74FA03F3, 0x5340DB33, 0x17EA96B1, 0x364BF5A5, 0x346915B8, 0x4C714F33, 0x74,       0}};

#endif /* __TEST_ECDOUBLEMUL_H */
