#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#pragma comment(linker, "/INCLUDE:__tls_used")

void NTAPI __cdecl_ThreadLocalStorageCallback(PVOID instance, DWORD dwReason, PVOID reserved);

#pragma data_seg(".CRT$XLB")
PIMAGE_TLS_CALLBACK p_thread_callback[] = { __cdecl_ThreadLocalStorageCallback, 0 };
#pragma data_seg()

typedef enum THREAD_INFORMATION_CLASS {
    ThreadBasicInformation,
    ThreadTimes,
    ThreadPriority,
    ThreadBasePriority,
    ThreadAffinityMask,
    ThreadImpersonationToken,
    ThreadDescriptorTableEntry,
    ThreadEnableAlignmentFaultFixup,
    ThreadEventPair,
    ThreadQuerySetWin32StartAddress,
    ThreadZeroTlsCell,
    ThreadPerformanceCount,
    ThreadAmILastThread,
    ThreadIdealProcessor,
    ThreadPriorityBoost,
    ThreadSetTlsArrayAddress,
    ThreadIsIoPending,
    ThreadHideFromDebugger
} THREAD_INFORMATION_CLASS, * PTHREAD_INFORMATION_CLASS;

typedef NTSTATUS(*PNTSETINFORMATIONTHREAD)(
    IN HANDLE ThreadHandle,
    IN THREAD_INFORMATION_CLASS ThreadInformationClass,
    IN PVOID ThreadInformation,
    IN ULONG ThreadInformationLength
    );

#pragma data_seg(."knpc")
char filename[] = "ESCAPE.ctf";
#pragma data_seg()

int main(void) { //f

    char txt[10] = { 0, };
    char cap[10] = { 0, };
    char f[256] = { 0, };
    char s[256] = { 0, };

    FILE* fp;
    int fSize = 0;

    HANDLE fHandle;
    HWND hWndConsole;

    hWndConsole = GetConsoleWindow();
    ShowWindow(hWndConsole, SW_HIDE);

    fopen_s(&fp, filename, "r");

    srand(time(NULL));

    if (fp == NULL) {
        MessageBoxA(NULL, "No File Found", "eRrOr", MB_ICONSTOP);
        exit(1);
    }
    else {
        fgets(f, 256, fp);
        fSize = ftell(fp);

        fclose(fp);

        if (fSize != 19) {
            return 0;
        }
        else {
            s[0] = (f[16] * f[0] - f[1] * f[14] + f[5] + f[17] * f[12] * f[18] + f[0] ^ f[11] * f[11] - f[11]) ^ 875097;
            s[1] = (f[1] - f[3] * f[10] ^ f[2] * f[4] + f[12] ^ f[0] * f[7] - f[0] * f[18] - f[5] + f[1]) ^ (-12677);
            s[2] = (f[3] ^ f[17] * f[3] - f[14] - f[5] - f[1] - f[6] + f[15] * f[1] ^ f[8] ^ f[11]) ^ 13248;
            s[3] = (f[15] ^ f[18] + f[4] + f[3] - f[6] * f[4] + f[8] ^ f[5] ^ f[9]) ^ (-9299);
            s[4] = (f[18] * f[7] + f[5] ^ f[3] - f[17] - f[1] ^ f[4] * f[18] * f[18] - f[7] - f[3] ^ f[12]) ^ -600235;
            s[5] = (f[3] ^ f[14] + f[8] - f[11] ^ f[14] * f[3] - f[15] + f[10]) ^ 7580;
            s[6] = (f[17] - f[15] - f[5] + f[11] - f[7] + f[17] * f[5] * f[2] ^ f[9] ^ f[3] ^ f[6]) ^ 451858;
            s[7] = (f[16] ^ f[16] * f[2] * f[5] - f[5] - f[7] ^ f[17] * f[9] * f[8]) ^ 179764;
            s[8] = (f[10] ^ f[17] * f[1] * f[10] * f[1] ^ f[4] * f[16] - f[15] * f[7] ^ f[6] ^ f[7] ^ f[4]) ^ -31611309;
            s[9] = (f[9] * f[15] - f[1] + f[2] - f[3] * f[14] + f[13] + f[9] * f[5] ^ f[3] * f[12]) ^ 5712;
            s[10] = (f[7] - f[3] * f[1] ^ f[9] + f[0] ^ f[12] - f[15] ^ f[11] ^ f[7] * f[5]) ^ -12013;
            s[11] = (f[5] ^ f[9] + f[11] - f[4] + f[6] * f[15] + f[16] ^ f[17] * f[2] + f[10] - f[6] + f[6]) ^ 7522;
            s[12] = (f[14] * f[8] ^ f[16] ^ f[7] - f[5] - f[9] + f[6] - f[12] * f[5]) ^ -15205;
            s[13] = (f[16] + f[6] + f[18] ^ f[17] * f[5] - f[0] + f[9] + f[16] ^ f[0]) ^ 11653;
            s[14] = (f[15] - f[2] ^ f[7] ^ f[0] * f[14] * f[2] ^ f[6] + f[11] ^ f[3]) ^ 270195;
            s[15] = (f[9] + f[7] * f[0] ^ f[16] * f[14] - f[8] - f[6] + f[5] - f[17] ^ f[10] + f[18] * f[2]) ^ 11581;
            s[16] = (f[16] ^ f[2] ^ f[7] - f[8] - f[6] + f[14] - f[8]) ^ -48;
            s[17] = (f[10] + f[11] ^ f[0] + f[12] ^ f[13] - f[8] - f[5] * f[10] ^ f[2] * f[3] * f[17] * f[0]) ^ -44732686;
            s[18] = (f[15] + f[8] * f[7] + f[8] * f[15] * f[5] - f[1] - f[12]) ^ 292242;
            s[19] = (f[1] - f[16] * f[9] + f[11] - f[18] - f[9] + f[14] * f[12] ^ f[0] * f[6]) ^ 8515;
            s[20] = (f[0] + f[16] * f[7] - f[10] + f[7] ^ f[3] * f[8] - f[7] + f[17] ^ f[11] + f[0]) ^ 3096;
            s[21] = (f[5] * f[17] * f[15] * f[1] * f[4] * f[2] ^ f[9] * f[8] - f[17] + f[9] ^ f[9]) ^ -238261210;
            s[22] = (f[18] ^ f[15] * f[5] - f[2] * f[17] * f[11] ^ f[8]) ^ -171877;
            s[23] = (f[11] ^ f[9] * f[14] ^ f[2] - f[7] ^ f[11] * f[11] + f[5] ^ f[4] * f[17] * f[1]) ^ -492488;
            s[24] = (f[12] ^ f[14] ^ f[5] * f[14] ^ f[13] + f[12] * f[11] * f[4] - f[13] - f[1]) ^ 527743;
            s[25] = (f[15] * f[9] ^ f[13] - f[13] - f[16] + f[10] ^ f[10]) ^ 4672;
            s[26] = (f[10] + f[3] ^ f[1] * f[2] - f[11] ^ f[13] * f[13] ^ f[8] * f[12]) ^ 15890;
            s[27] = (f[8] ^ f[4] + f[2] * f[18] ^ f[8] ^ f[17] ^ f[14] * f[6]) ^ 5758;
            s[28] = (f[15] * f[4] - f[8] ^ f[13] ^ f[15] + f[11] * f[8] ^ f[16] + f[10]) ^ 6271;
            s[29] = (f[5] * f[7] + f[12] + f[0] + f[4] - f[2] + f[6] + f[6] ^ f[10] + f[1]) ^ 14559;
            s[30] = (f[6] + f[9] - f[4] ^ f[14] ^ f[1] * f[5] * f[0] * f[9] - f[1]) ^ 66932212;
            s[31] = (f[9] ^ f[5] ^ f[5] ^ f[11] ^ f[7] * f[6] * f[5] ^ f[7] + f[4] * f[0] * f[5]) ^ 523603;
            s[32] = (f[2] ^ f[16] - f[1] + f[10] - f[16] ^ f[12] - f[9]) ^ 80;
            s[33] = (f[9] - f[15] + f[18] * f[0] * f[13] - f[9] ^ f[3] - f[0] + f[7] ^ f[8] - f[10]) ^ -787997;
            s[34] = (f[10] ^ f[5] - f[4] ^ f[1] + f[3] - f[15] - f[2] - f[0]) ^ -49;
            s[35] = (f[5] + f[18] * f[13] ^ f[1] * f[11] * f[11] * f[6] * f[8] * f[10]) ^ -1142227560;

            txt[0] = s[rand() % 2];
            txt[2] = s[(rand() % 2) + 4];
            txt[3] = s[(rand() % 2) + 6];
            txt[8] = s[(rand() % 2) + 16];
            txt[5] = s[11 - (rand() % 2)];
            txt[7] = s[(rand() % 2) + 14];
            txt[4] = s[(rand() % 2) + 8];
            txt[6] = s[13 - (rand() % 2)];
            txt[1] = s[3 - (rand() % 2)];
            txt[9] = NULL;

            cap[0] = s[(rand() % 2) + 18];
            cap[1] = s[(rand() % 2) + 20];
            cap[2] = s[(rand() % 2) + 22];
            cap[3] = s[(rand() % 2) + 24];
            cap[4] = s[(rand() % 2) + 26];
            cap[5] = s[(rand() % 2) + 28];
            cap[6] = 'O';
            cap[7] = s[(rand() % 2) + 32];
            cap[8] = s[(rand() % 2) + 34];
            cap[9] = NULL;


            MessageBoxA(NULL, txt, cap, MB_OK);
        }
    }


}

void NTAPI __cdecl_ThreadLocalStorageCallback(PVOID instance, DWORD dwReason, PVOID reserved) { //t
    char txt[10] = { 0, };
    char cap[10] = { 0, };
    char f[256] = { 0, };
    char s[256] = { 0, };

    FILE* fp;
    int fSize = 0;

    HWND hwnd;

    if (IsDebuggerPresent()==0) {

        hwnd = GetConsoleWindow();
        ShowWindow(hwnd, SW_HIDE);

        fopen_s(&fp, filename, "r");

        srand(time(NULL));

        if (fp == NULL) {
            MessageBoxA(NULL, "No File Found", "eRr0r", MB_ICONSTOP);
            exit(1);
        }
        else {

            fgets(f, 256, fp);
            fSize = ftell(fp);

            fclose(fp);

            if (fSize != 28) return 1;
            else {
                s[0] = (f[12] - f[20] * f[3] - f[24] + f[11] + f[18] + f[12] ^ f[8]) ^ -3273;
                s[1] = (f[13] - f[14] + f[15] - f[6] - f[20] ^ f[14] * f[6] ^ f[17] - f[26] ^ f[3]) ^ -11069;
                s[2] = (f[18] + f[18] * f[1] * f[25] * f[8] * f[10] ^ f[16] + f[23] + f[5]) ^ -560840432;
                s[3] = (f[20] ^ f[16] * f[25] * f[14] + f[10] * f[12] - f[12] ^ f[13] * f[18] - f[9]) ^ 367670;
                s[4] = (f[12] * f[7] + f[27] ^ f[0] - f[14] ^ f[15] * f[1] * f[24] - f[4] * f[3]) ^ -778883;
                s[5] = (f[25] * f[14] - f[24] ^ f[9] + f[13] ^ f[5] * f[24] ^ f[11] ^ f[7] * f[28] * f[9]) ^ 5454;
                s[6] = (f[8] + f[11] ^ f[20] - f[23] * f[8] - f[25] * f[26] * f[4]) ^ -267633;
                s[7] = (f[8] * f[23] ^ f[8] - f[24] - f[7] + f[11] - f[2] * f[23] - f[1] + f[0] - f[1] ^ f[3]) ^ -265;
                s[8] = (f[27] - f[26] - f[4] * f[16] ^ f[3] - f[9] - f[2]) ^ 9592;
                s[9] = (f[2] + f[28] * f[21] + f[18] + f[5] ^ f[23] ^ f[3] * f[7] ^ f[11]) ^ 4575;
                s[10] = (f[15] - f[26] + f[11] + f[21] + f[7] ^ f[27] * f[18] * f[5] + f[8] * f[15] + f[11]) ^ 879377;
                s[11] = (f[19] - f[3] * f[0] * f[13] - f[15] - f[28] ^ f[19] * f[8]) ^ -404147;
                s[12] = (f[24] - f[13] - f[12] + f[25] * f[2] * f[11] * f[2] ^ f[3] * f[25] - f[5] * f[8]) ^ -35883964;
                s[13] = (f[28] + f[5] - f[25] * f[4] + f[18] * f[15] + f[5] ^ f[19] - f[12] * f[0]) ^ -14927;
                s[14] = (f[6] * f[28] + f[10] - f[14] + f[18] - f[28] ^ f[0] * f[4] ^ f[7] - f[6] ^ f[17] + f[3]) ^ -5840;
                s[15] = (f[10] * f[22] + f[0] ^ f[19] ^ f[0] - f[20] * f[0]) ^ -14527;
                s[16] = (f[4] - f[25] - f[1] + f[7] - f[12] ^ f[25] * f[0] - f[9]) ^ -2247;
                s[17] = (f[1] * f[20] ^ f[21] ^ f[8] - f[9] ^ f[23] ^ f[19] + f[12] ^ f[16] + f[19] + f[12]) ^ -6923;
                s[18] = (f[25] * f[1] * f[27] ^ f[14] - f[21] - f[14] + f[5] * f[19] + f[3] + f[15] ^ f[6] - f[5]) ^ 220706;
                s[19] = (f[28] - f[18] - f[13] ^ f[0] - f[19] + f[1] + f[6] ^ f[28] ^ f[5] * f[16] * f[18] * f[5]) ^ -158571284;
                s[20] = (f[2] ^ f[13] - f[4] * f[9] + f[19] - f[6] + f[6] ^ f[10] + f[2]) ^ -8867;
                s[21] = (f[18] + f[1] ^ f[17] + f[19] * f[1] + f[4] - f[4] + f[12] * f[11] - f[5]) ^ 15778;
                s[22] = (f[11] + f[6] * f[8] - f[11] - f[16] ^ f[24] - f[28] - f[12] * f[21] * f[6]) ^ -510999;
                s[23] = (f[1] * f[20] ^ f[7] * f[19] + f[11] - f[26] * f[20] + f[11]) ^ 8113;
                s[24] = (f[23] + f[4] ^ f[16] * f[16] - f[11] ^ f[24] + f[17] * f[18] + f[12]) ^ 1080;
                s[25] = (f[14] ^ f[12] - f[5] - f[26] - f[19] * f[2] ^ f[27] * f[9]) ^ -14013;
                s[26] = (f[6] ^ f[2] + f[6] - f[5] * f[7] ^ f[17] - f[23] + f[6]) ^ -9068;
                s[27] = (f[18] + f[0] - f[24] ^ f[5] - f[0] + f[14] - f[13] - f[18] - f[4]) ^ -157;
                s[28] = (f[6] * f[13] + f[22] + f[8] + f[9] * f[21] * f[13] - f[14] - f[16] - f[7]) ^ 806605;
                s[29] = (f[22] - f[19] ^ f[28] - f[15] - f[7] ^ f[8] ^ f[28] - f[13] * f[16] - f[6]) ^ 13273;
                s[30] = (f[6] * f[0] ^ f[9] + f[5] + f[18] + f[9] - f[2] - f[8] + f[16] ^ f[1]) ^ 7926;
                s[31] = (f[2] - f[15] ^ f[11] * f[25] - f[4] ^ f[16] * f[26] * f[5] + f[14] ^ f[2]) ^ -1258120;
                s[32] = (f[22] ^ f[18] + f[23] - f[20] * f[12] + f[12] ^ f[8] * f[7] + f[17] * f[28] * f[5]) ^ -13215;
                s[33] = (f[25] * f[2] - f[2] * f[8] - f[1] * f[21] * f[4]) ^ -524776;
                s[34] = (f[9] ^ f[18] ^ f[20] * f[2] * f[10] ^ f[24] + f[24] * f[5]) ^ 759268;
                s[35] = (f[5] - f[24] * f[12] * f[5] * f[4] * f[5] ^ f[11]) ^ -514165330;
                s[36] = (f[26] - f[16] ^ f[3] ^ f[19] * f[1] - f[23] + f[12] + f[6]) ^ -9362;
                s[37] = (f[15] - f[26] ^ f[26] + f[21] * f[17] - f[16] * f[7]) ^ -2360;
                s[38] = (f[28] * f[17] ^ f[3] ^ f[28] * f[17] + f[5] - f[0] + f[17] ^ f[14] * f[11]) ^ 9181;
                s[39] = (f[4] + f[2] ^ f[23] + f[25] - f[2] + f[12] * f[28] - f[23] + f[9]) ^ 218;
                s[40] = (f[9] + f[28] ^ f[23] ^ f[15] - f[14] ^ f[18] + f[13] ^ f[12]) ^ 146;
                s[41] = (f[27] - f[17] - f[7] ^ f[7] + f[24] ^ f[1] ^ f[27] - f[6]) ^ 235;
                s[42] = (f[1] - f[2] ^ f[28] - f[4] - f[22] - f[7] + f[10] - f[15] * f[16] * f[2] + f[12] - f[1]) ^ 1452340;
                s[43] = (f[6] * f[5] ^ f[23] - f[11] + f[16] + f[16] ^ f[5]) ^ 12835;
                s[44] = (f[13] * f[21] * f[24] * f[14] + f[17] + f[16] * f[3]) ^ 47985902;
                s[45] = (f[21] - f[12] ^ f[4] * f[14] ^ f[26] - f[2] - f[23] ^ f[26] + f[7]) ^ 7893;
                s[46] = (f[8] * f[9] * f[0] - f[2] * f[24] ^ f[8] * f[8] - f[3] * f[27] + f[22] ^ f[10]) ^ 796144;
                s[47] = (f[6] + f[23] - f[8] ^ f[23] ^ f[15] + f[9] - f[25] - f[12] ^ f[3]) ^ 114;
                s[48] = (f[13] + f[13] * f[9] * f[24] * f[6] + f[23] * f[1] ^ f[11]) ^ 100004948;
                s[49] = (f[20] ^ f[2] - f[24] ^ f[16] - f[16] - f[7] * f[19] ^ f[2]) ^ -8055;
                s[50] = (f[14] - f[12] - f[14] ^ f[28] + f[1] ^ f[11] ^ f[21] * f[3] ^ f[26] * f[7]) ^ -4880;
                s[51] = (f[23] ^ f[7] + f[27] * f[4] ^ f[19] - f[18] - f[7] * f[3] ^ f[0]) ^ -2047;
                s[52] = (f[0] ^ f[17] ^ f[13] + f[10] ^ f[18] + f[20] + f[21] * f[0]) ^ 4809;
                s[53] = (f[3] + f[15] * f[16] - f[5] * f[23] ^ f[28] - f[1] + f[18] + f[6] ^ f[22] + f[7]) ^ 8052;

                txt[0] = s[rand() % 3];
                txt[2] = s[(rand() % 3) + 6];
                txt[3] = s[(rand() % 3) + 9];
                txt[8] = s[(rand() % 3) + 24];
                txt[5] = s[17 - (rand() % 3)];
                txt[7] = s[(rand() % 3) + 21];
                txt[4] = s[(rand() % 3) + 12];
                txt[6] = s[20 - (rand() % 3)];
                txt[1] = s[5 - (rand() % 3)];
                txt[9] = NULL;

                cap[0] = s[(rand() % 3) + 27];
                cap[1] = s[(rand() % 3) + 30];
                cap[2] = s[(rand() % 3) + 33];
                cap[3] = s[(rand() % 3) + 36];
                cap[4] = s[(rand() % 3) + 39];
                cap[5] = s[(rand() % 3) + 42];
                cap[6] = s[(rand() % 3) + 45];
                cap[7] = s[(rand() % 3) + 48];
                cap[8] = s[(rand() % 3) + 51];
                cap[9] = NULL;

                MessageBoxA(NULL, txt, cap, MB_OK);
                exit(1);
            }

        }
    }

    return 0;
}
