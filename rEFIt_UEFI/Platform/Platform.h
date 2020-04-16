/*
Headers collection for procedures
*/

#ifndef __REFIT_PLATFORM_H__
#define __REFIT_PLATFORM_H__

// Set all debug options - apianti
// Uncomment to set all debug options
// Comment to use source debug options
//#define DEBUG_ALL 2

#include "Posix/posix.h"


#ifdef __cplusplus
extern "C" {
#endif

#include <Library/printf_lite.h>

#include <Uefi.h>

#include <Guid/Acpi.h>
#include <Guid/EventGroup.h>
#include <Guid/SmBios.h>
#include <Guid/Mps.h>

#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/DevicePathLib.h>
#include <Library/DeviceTreeLib.h>
#include <Library/GenericBdsLib.h>
#include <Library/HiiLib.h>
#include <Library/HdaModels.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/PrintLib.h>
#include <Library/PerformanceLib.h>
#include <Library/PeCoffGetEntryPointLib.h>
#include <Library/TimerLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiRuntimeLib.h>
#include <Library/UsbMass.h>
#include <Library/VideoBiosPatchLib.h>
#include <Library/MemLogLib.h>
#include <Library/WaveLib.h>

#include <Framework/FrameworkInternalFormRepresentation.h>

#include <IndustryStandard/Acpi10.h>
#include <IndustryStandard/Acpi20.h>
#include <IndustryStandard/Atapi.h>
#include <IndustryStandard/AppleHid.h>
#include <IndustryStandard/AppleSmBios.h>
#include <IndustryStandard/AppleFeatures.h>
#include <IndustryStandard/Bmp.h>
#include <IndustryStandard/HdaCodec.h>

#include <Protocol/PciIo.h>
#include <Protocol/AudioIo.h>
#include <Protocol/Cpu.h>
#include <Protocol/CpuIo.h>
#include <Protocol/DataHub.h>
#include <Protocol/DevicePathToText.h>
#include <Protocol/EdidDiscovered.h>
#include <Protocol/EdidOverride.h>
#include <Protocol/FrameworkHii.h>
#include <Protocol/HdaIo.h>
#include <Protocol/SimplePointer.h>
#include <Protocol/Smbios.h>
#include <Protocol/VariableWrite.h>
#include <Protocol/Variable.h>
#include <Protocol/UgaDraw.h>

#include <Protocol/FSInjectProtocol.h>
#include <Protocol/MsgLog.h>
#include <Protocol/efiConsoleControl.h>
#include <Protocol/EmuVariableControl.h>
#include <Protocol/AppleSMC.h>
#include <Protocol/AppleImageCodecProtocol.h>

#ifdef __cplusplus
}
#endif


// cpp_foundation objects has to be included before lib.h
#ifdef __cplusplus
#include "../cpp_foundation/XString.h"
#include "../cpp_foundation/XStringW.h"
#include "../cpp_foundation/XArray.h"
#include "../cpp_foundation/XObjArray.h"
#include "../cpp_util/remove_ref.h"
#endif

#include "../entry_scan/common.h"
#include "../libeg/BmLib.h"
#include "BootLog.h"
#include "BasicIO.h"
#include "../refit/lib.h"
#include "../refit/screen.h" // for PauseForKey
#include "string.h"
#include "boot.h"
#include "plist.h"
//#include "PiBootMode.h"
#ifndef CLOVERAPPLICATION
#include "../refit/IO.h"
#endif

#include "device_inject.h"

#ifdef __cplusplus
#include "kext_inject.h"
//#include "entry_scan.h"
#endif

#include "Settings.h"

#define CLOVER_SIGN             SIGNATURE_32('C','l','v','r')
#define NON_APPLE_SMC_SIGNATURE SIGNATURE_64('S','M','C','H','E','L','P','E')

#define PCAT_RTC_ADDRESS_REGISTER 0x70
#define PCAT_RTC_DATA_REGISTER    0x71

#ifdef _MSC_VER
#define __typeof__(x) decltype(x)
#endif
#define __typeof_am__(x) remove_ref<decltype(x)>::type


/* XML Tags */
#define kXMLTagPList     "plist"
#define kXMLTagDict      "dict"
#define kXMLTagKey       "key"
#define kXMLTagString    "string"
#define kXMLTagInteger   "integer"
#define kXMLTagData      "data"
#define kXMLTagDate      "date"
#define kXMLTagFalse     "false/"
#define kXMLTagTrue      "true/"
#define kXMLTagArray     "array"
#define kXMLTagReference "reference"
#define kXMLTagID        "ID="
#define kXMLTagIDREF     "IDREF="

#define MAX_NUM_DEVICES  64

#define HEIGHT_2K 1100

/* Decimal powers: */
#define kilo (1000ULL)
#define Mega (kilo * kilo)
#define Giga (kilo * Mega)
#define Tera (kilo * Giga)
#define Peta (kilo * Tera)

#define EBDA_BASE_ADDRESS            0x40E
#define EFI_SYSTEM_TABLE_MAX_ADDRESS 0xFFFFFFFF
#define ROUND_PAGE(x)                ((((unsigned)(x)) + EFI_PAGE_SIZE - 1) & ~(EFI_PAGE_SIZE - 1))

//
// Max bytes needed to represent ID of a SCSI device
//
#define EFI_SCSI_TARGET_MAX_BYTES (0x10)

//
// bit5..7 are for Logical unit number
// 11100000b (0xe0)
//
#define EFI_SCSI_LOGICAL_UNIT_NUMBER_MASK 0xe0

//
// Scsi Command Length
//
#define EFI_SCSI_OP_LENGTH_SIX      0x6
#define EFI_SCSI_OP_LENGTH_TEN      0xa
#define EFI_SCSI_OP_LENGTH_SIXTEEN  0x10

//#define SAFE_LOG_SIZE  80

#define MSG_LOG_SIZE (256 * 1024)
#define PREBOOT_LOG  L"EFI\\CLOVER\\misc\\preboot.log"
#define LEGBOOT_LOG  L"EFI\\CLOVER\\misc\\legacy_boot.log"
#define BOOT_LOG     L"EFI\\CLOVER\\misc\\boot.log"
#define SYSTEM_LOG   L"EFI\\CLOVER\\misc\\system.log"
#define DEBUG_LOG    L"EFI\\CLOVER\\misc\\debug.log"
#define PREWAKE_LOG  L"EFI\\CLOVER\\misc\\prewake.log"

#ifndef DEBUG_ALL
#define MsgLog(...)  DebugLog(1, __VA_ARGS__)
#else
#define MsgLog(...)  DebugLog(DEBUG_ALL, __VA_ARGS__)
#endif

#define CPU_MODEL_PENTIUM_M     0x09
#define CPU_MODEL_DOTHAN        0x0D
#define CPU_MODEL_YONAH         0x0E
#define CPU_MODEL_MEROM         0x0F  /* same as CONROE but mobile */
#define CPU_MODEL_CONROE        0x0F  /* Allendale, Conroe, Kentsfield, Woodcrest, Clovertown, Tigerton */
#define CPU_MODEL_CELERON       0x16  /* ever see? */
#define CPU_MODEL_PENRYN        0x17  /* Yorkfield, Harpertown, Penryn M */
#define CPU_MODEL_WOLFDALE      0x17  /* kind of penryn but desktop */
#define CPU_MODEL_NEHALEM       0x1A  /* Bloomfield. Nehalem-EP, Nehalem-WS, Gainestown */
#define CPU_MODEL_ATOM          0x1C  /* Pineview UN */
#define CPU_MODEL_XEON_MP       0x1D  /* MP 7400 UN */
#define CPU_MODEL_FIELDS        0x1E  /* Lynnfield, Clarksfield, Jasper */
#define CPU_MODEL_DALES         0x1F  /* Havendale, Auburndale */
#define CPU_MODEL_CLARKDALE     0x25  /* Clarkdale, Arrandale */
#define CPU_MODEL_ATOM_SAN      0x26  /* Haswell H ? */
#define CPU_MODEL_LINCROFT      0x27  /* UN */
#define CPU_MODEL_SANDY_BRIDGE  0x2A
#define CPU_MODEL_WESTMERE      0x2C  /* Gulftown LGA1366 */
#define CPU_MODEL_JAKETOWN      0x2D  /* Sandy Bridge Xeon LGA2011 */
#define CPU_MODEL_NEHALEM_EX    0x2E
#define CPU_MODEL_WESTMERE_EX   0x2F
#define CPU_MODEL_ATOM_Z8000    0x35
#define CPU_MODEL_ATOM_2000     0x36  /* UN */
#define CPU_MODEL_ATOM_3700     0x37  /* Bay Trail */
#define CPU_MODEL_IVY_BRIDGE    0x3A
#define CPU_MODEL_HASWELL       0x3C  /* Haswell DT */
#define CPU_MODEL_HASWELL_U5    0x3D  /* Haswell U5  5th generation Broadwell*/
#define CPU_MODEL_IVY_BRIDGE_E5 0x3E  /* Ivy Bridge Xeon UN */
#define CPU_MODEL_HASWELL_E     0x3F  /* Haswell Extreme */
//#define CPU_MODEL_HASWELL_H    0x??  // Haswell H
#define CPU_MODEL_HASWELL_ULT   0x45  /* Haswell ULT */
#define CPU_MODEL_CRYSTALWELL   0x46  /* Haswell ULX CPUID_MODEL_CRYSTALWELL */
#define CPU_MODEL_BROADWELL_HQ  0x47  /* E3-1200 v4 */
#define CPU_MODEL_MERRIFIELD    0x4A  /* Tangier */
#define CPU_MODEL_AIRMONT       0x4C  /* CherryTrail / Braswell */
#define CPU_MODEL_AVOTON        0x4D  /* Avaton/Rangely */
#define CPU_MODEL_SKYLAKE_U     0x4E  /* Skylake Mobile */
#define CPU_MODEL_BROADWELL_E5  0x4F  /* Xeon E5-2695 */
#define CPU_MODEL_SKYLAKE_S     0x55  /* Skylake Server, Cooper Lake */
#define CPU_MODEL_BROADWELL_DE  0x56  /* Xeon BroadWell */
#define CPU_MODEL_KNIGHT        0x57  /* Knights Landing */
#define CPU_MODEL_MOOREFIELD    0x5A  /* Annidale */
#define CPU_MODEL_GOLDMONT      0x5C  /* Apollo Lake */
#define CPU_MODEL_ATOM_X3       0x5D  /* Silvermont */
#define CPU_MODEL_SKYLAKE_D     0x5E  /* Skylake Desktop */
#define CPU_MODEL_DENVERTON     0x5F  /* Goldmont Microserver */
#define CPU_MODEL_CANNONLAKE    0x66
#define CPU_MODEL_ICELAKE_A     0x6A  /* Xeon Ice Lake */
#define CPU_MODEL_ICELAKE_C     0x6C  /* Xeon Ice Lake */
#define CPU_MODEL_ATOM_GM       0x7A  /* Goldmont Plus */
#define CPU_MODEL_ICELAKE_D     0x7D
#define CPU_MODEL_ICELAKE       0x7E
#define CPU_MODEL_XEON_MILL     0x85  /* Knights Mill */
#define CPU_MODEL_ATOM_TM       0x86  /* Tremont */
#define CPU_MODEL_KABYLAKE1     0x8E  /* Kabylake Mobile */
#define CPU_MODEL_KABYLAKE2     0x9E  /* Kabylake Dektop, CoffeeLake */
#define CPU_MODEL_COMETLAKE_S   0x9F  /* desktop Comet Lake */
#define CPU_MODEL_COMETLAKE_Y   0xA5  /* aka 10th generation Amber Lake Y */
#define CPU_MODEL_COMETLAKE_U   0xA6

#define CPU_VENDOR_INTEL        0x756E6547
#define CPU_VENDOR_AMD          0x68747541
/* Unknown CPU */
#define CPU_STRING_UNKNOWN      "Unknown CPU Type"

//definitions from Apple XNU

/* CPU defines */
#define bit(n)                  (1UL << (n))
#define _Bit(n)                 (1ULL << (n))
#define _HBit(n)                (1ULL << ((n)+32))

#define bitmask(h,l)            ((bit(h)|(bit(h)-1)) & ~(bit(l)-1))
#define bitfield(x,h,l)          RShiftU64(((x) & bitmask((h),(l))), (l))
#define quad(hi,lo)             ((LShiftU64((hi), 32) | (lo)))

/*
 * The CPUID_FEATURE_XXX values define 64-bit values
 * returned in %ecx:%edx to a CPUID request with %eax of 1:
 */
#define  CPUID_FEATURE_FPU      _Bit(0)  /* Floating point unit on-chip */
#define  CPUID_FEATURE_VME      _Bit(1)  /* Virtual Mode Extension */
#define  CPUID_FEATURE_DE       _Bit(2)  /* Debugging Extension */
#define  CPUID_FEATURE_PSE      _Bit(3)  /* Page Size Extension */
#define  CPUID_FEATURE_TSC      _Bit(4)  /* Time Stamp Counter */
#define  CPUID_FEATURE_MSR      _Bit(5)  /* Model Specific Registers */
#define CPUID_FEATURE_PAE       _Bit(6)  /* Physical Address Extension */
#define  CPUID_FEATURE_MCE      _Bit(7)  /* Machine Check Exception */
#define  CPUID_FEATURE_CX8      _Bit(8)  /* CMPXCHG8B */
#define  CPUID_FEATURE_APIC     _Bit(9)  /* On-chip APIC */
#define CPUID_FEATURE_SEP       _Bit(11)  /* Fast System Call */
#define  CPUID_FEATURE_MTRR     _Bit(12)  /* Memory Type Range Register */
#define  CPUID_FEATURE_PGE      _Bit(13)  /* Page Global Enable */
#define  CPUID_FEATURE_MCA      _Bit(14)  /* Machine Check Architecture */
#define  CPUID_FEATURE_CMOV     _Bit(15)  /* Conditional Move Instruction */
#define CPUID_FEATURE_PAT       _Bit(16)  /* Page Attribute Table */
#define CPUID_FEATURE_PSE36     _Bit(17)  /* 36-bit Page Size Extension */
#define CPUID_FEATURE_PSN       _Bit(18)  /* Processor Serial Number */
#define CPUID_FEATURE_CLFSH     _Bit(19)  /* CLFLUSH Instruction supported */
#define CPUID_FEATURE_DS        _Bit(21)  /* Debug Store */
#define CPUID_FEATURE_ACPI      _Bit(22)  /* Thermal monitor and Clock Ctrl */
#define CPUID_FEATURE_MMX       _Bit(23)  /* MMX supported */
#define CPUID_FEATURE_FXSR      _Bit(24)  /* Fast floating pt save/restore */
#define CPUID_FEATURE_SSE       _Bit(25)  /* Streaming SIMD extensions */
#define CPUID_FEATURE_SSE2      _Bit(26)  /* Streaming SIMD extensions 2 */
#define CPUID_FEATURE_SS        _Bit(27)  /* Self-Snoop */
#define CPUID_FEATURE_HTT       _Bit(28)  /* Hyper-Threading Technology */
#define CPUID_FEATURE_TM        _Bit(29)  /* Thermal Monitor (TM1) */
#define CPUID_FEATURE_PBE       _Bit(31)  /* Pend Break Enable */

#define CPUID_FEATURE_SSE3      _HBit(0)  /* Streaming SIMD extensions 3 */
#define CPUID_FEATURE_PCLMULQDQ _HBit(1) /* PCLMULQDQ Instruction */
#define CPUID_FEATURE_DTES64    _HBit(2)  /* 64-bit DS layout */
#define CPUID_FEATURE_MONITOR   _HBit(3)  /* Monitor/mwait */
#define CPUID_FEATURE_DSCPL     _HBit(4)  /* Debug Store CPL */
#define CPUID_FEATURE_VMX       _HBit(5)  /* VMX */
#define CPUID_FEATURE_SMX       _HBit(6)  /* SMX */
#define CPUID_FEATURE_EST       _HBit(7)  /* Enhanced SpeedsTep (GV3) */
#define CPUID_FEATURE_TM2       _HBit(8)  /* Thermal Monitor 2 */
#define CPUID_FEATURE_SSSE3     _HBit(9)  /* Supplemental SSE3 instructions */
#define CPUID_FEATURE_CID       _HBit(10)  /* L1 Context ID */
#define CPUID_FEATURE_SEGLIM64  _HBit(11) /* 64-bit segment limit checking */
#define CPUID_FEATURE_CX16      _HBit(13)  /* CmpXchg16b instruction */
#define CPUID_FEATURE_xTPR      _HBit(14)  /* Send Task PRiority msgs */
#define CPUID_FEATURE_PDCM      _HBit(15)  /* Perf/Debug Capability MSR */

#define CPUID_FEATURE_PCID      _HBit(17) /* ASID-PCID support */
#define CPUID_FEATURE_DCA       _HBit(18)  /* Direct Cache Access */
#define CPUID_FEATURE_SSE4_1    _HBit(19)  /* Streaming SIMD extensions 4.1 */
#define CPUID_FEATURE_SSE4_2    _HBit(20)  /* Streaming SIMD extensions 4.2 */
#define CPUID_FEATURE_xAPIC     _HBit(21)  /* Extended APIC Mode */
#define CPUID_FEATURE_MOVBE     _HBit(22) /* MOVBE instruction */
#define CPUID_FEATURE_POPCNT    _HBit(23)  /* POPCNT instruction */
#define CPUID_FEATURE_TSCTMR    _HBit(24) /* TSC deadline timer */
#define CPUID_FEATURE_AES       _HBit(25)  /* AES instructions */
#define CPUID_FEATURE_XSAVE     _HBit(26) /* XSAVE instructions */
#define CPUID_FEATURE_OSXSAVE   _HBit(27) /* XGETBV/XSETBV instructions */
#define CPUID_FEATURE_AVX1_0    _HBit(28) /* AVX 1.0 instructions */
#define CPUID_FEATURE_RDRAND    _HBit(29) /* RDRAND instruction */
#define CPUID_FEATURE_F16C      _HBit(30) /* Float16 convert instructions */
#define CPUID_FEATURE_VMM       _HBit(31)  /* VMM (Hypervisor) present */

/*
 * Leaf 7, subleaf 0 additional features.
 * Bits returned in %ebx to a CPUID request with {%eax,%ecx} of (0x7,0x0}:
 */
#define CPUID_LEAF7_FEATURE_RDWRFSGS _Bit(0)  /* FS/GS base read/write */
#define CPUID_LEAF7_FEATURE_SMEP     _Bit(7)  /* Supervisor Mode Execute Protect */
#define CPUID_LEAF7_FEATURE_ENFSTRG  _Bit(9)  /* ENhanced Fast STRinG copy */


/*
 * The CPUID_EXTFEATURE_XXX values define 64-bit values
 * returned in %ecx:%edx to a CPUID request with %eax of 0x80000001:
 */
#define CPUID_EXTFEATURE_SYSCALL   _Bit(11)  /* SYSCALL/sysret */
#define CPUID_EXTFEATURE_XD        _Bit(20)  /* eXecute Disable */
#define CPUID_EXTFEATURE_1GBPAGE   _Bit(26)     /* 1G-Byte Page support */
#define CPUID_EXTFEATURE_RDTSCP    _Bit(27)  /* RDTSCP */
#define CPUID_EXTFEATURE_EM64T     _Bit(29)  /* Extended Mem 64 Technology */

//#define CPUID_EXTFEATURE_LAHF    _HBit(20)  /* LAFH/SAHF instructions */
// New definition with Snow kernel
#define CPUID_EXTFEATURE_LAHF      _HBit(0)  /* LAHF/SAHF instructions */
/*
 * The CPUID_EXTFEATURE_XXX values define 64-bit values
 * returned in %ecx:%edx to a CPUID request with %eax of 0x80000007:
 */
#define CPUID_EXTFEATURE_TSCI      _Bit(8)  /* TSC Invariant */

#define  CPUID_CACHE_SIZE  16  /* Number of descriptor values */

#define CPUID_MWAIT_EXTENSION  _Bit(0)  /* enumeration of WMAIT extensions */
#define CPUID_MWAIT_BREAK  _Bit(1)  /* interrupts are break events     */

/* Known MSR registers */
#define MSR_IA32_PLATFORM_ID        0x0017
#define IA32_APIC_BASE              0x001B  /* used also for AMD */
#define MSR_CORE_THREAD_COUNT       0x0035   /* limited use - not for Penryn or older  */
#define IA32_TSC_ADJUST             0x003B
#define MSR_IA32_BIOS_SIGN_ID       0x008B   /* microcode version */
#define MSR_FSB_FREQ                0x00CD   /* limited use - not for i7            */
/*
•  101B: 100 MHz (FSB 400)
•  001B: 133 MHz (FSB 533)
•  011B: 167 MHz (FSB 667)
•  010B: 200 MHz (FSB 800)
•  000B: 267 MHz (FSB 1067)
•  100B: 333 MHz (FSB 1333)
•  110B: 400 MHz (FSB 1600)
 */
// T8300 -> 0x01A2 => 200MHz
#define  MSR_PLATFORM_INFO          0x00CE   /* limited use - MinRatio for i7 but Max for Yonah  */
                                             /* turbo for penryn */
//haswell
//Low Frequency Mode. LFM is Pn in the P-state table. It can be read at MSR CEh [47:40].
//Minimum Frequency Mode. MFM is the minimum ratio supported by the processor and can be read from MSR CEh [55:48].
#define MSR_PKG_CST_CONFIG_CONTROL  0x00E2   /* sandy and up */
#define MSR_PMG_IO_CAPTURE_BASE     0x00E4  /* sandy and up */
#define IA32_MPERF                  0x00E7   /* TSC in C0 only */
#define IA32_APERF                  0x00E8   /* actual clocks in C0 */
#define MSR_IA32_EXT_CONFIG         0x00EE   /* limited use - not for i7            */
#define MSR_FLEX_RATIO              0x0194   /* limited use - not for Penryn or older      */
                                             //see no value on most CPUs
#define  MSR_IA32_PERF_STATUS       0x0198
#define MSR_IA32_PERF_CONTROL       0x0199
#define MSR_IA32_CLOCK_MODULATION   0x019A
#define MSR_THERMAL_STATUS          0x019C
#define MSR_IA32_MISC_ENABLE        0x01A0
#define MSR_THERMAL_TARGET          0x01A2   /* TjMax limited use - not for Penryn or older      */
#define MSR_TURBO_RATIO_LIMIT       0x01AD   /* limited use - not for Penryn or older      */


#define IA32_ENERGY_PERF_BIAS       0x01B0
//MSR 000001B0                                      0000-0000-0000-0005
#define MSR_PACKAGE_THERM_STATUS    0x01B1
//MSR 000001B1                                      0000-0000-8838-0000
#define IA32_PLATFORM_DCA_CAP       0x01F8
//MSR 000001FC                                      0000-0000-0004-005F


// Sandy Bridge & JakeTown specific 'Running Average Power Limit' MSR's.
#define MSR_RAPL_POWER_UNIT         0x606     /* R/O */
//MSR 00000606                                      0000-0000-000A-1003
#define MSR_PKGC3_IRTL              0x60A    /* RW time limit to go C3 */
          // bit 15 = 1 -- the value valid for C-state PM
#define MSR_PKGC6_IRTL              0x60B    /* RW time limit to go C6 */
//MSR 0000060B                                      0000-0000-0000-8854
  //Valid + 010=1024ns + 0x54=84mks
#define MSR_PKGC7_IRTL              0x60C    /* RW time limit to go C7 */
//MSR 0000060C                                      0000-0000-0000-8854
#define MSR_PKG_C2_RESIDENCY        0x60D   /* same as TSC but in C2 only */

#define MSR_PKG_RAPL_POWER_LIMIT    0x610
//MSR 00000610                                      0000-A580-0000-8960
#define MSR_PKG_ENERGY_STATUS       0x611
//MSR 00000611                                      0000-0000-3212-A857
#define MSR_PKG_POWER_INFO          0x614
//MSR 00000614                                      0000-0000-01E0-02F8
// Sandy Bridge IA (Core) domain MSR's.
#define MSR_PP0_POWER_LIMIT         0x638
#define MSR_PP0_ENERGY_STATUS       0x639
#define MSR_PP0_POLICY              0x63A
#define MSR_PP0_PERF_STATUS         0x63B

// Sandy Bridge Uncore (IGPU) domain MSR's (Not on JakeTown).
#define MSR_PP1_POWER_LIMIT         0x640
#define MSR_PP1_ENERGY_STATUS       0x641
//MSR 00000641                                      0000-0000-0000-0000
#define MSR_PP1_POLICY              0x642

// JakeTown only Memory MSR's.
#define MSR_PKG_PERF_STATUS         0x613
#define MSR_DRAM_POWER_LIMIT        0x618
#define MSR_DRAM_ENERGY_STATUS      0x619
#define MSR_DRAM_PERF_STATUS        0x61B
#define MSR_DRAM_POWER_INFO         0x61C

//IVY_BRIDGE
#define MSR_CONFIG_TDP_NOMINAL      0x648
#define MSR_CONFIG_TDP_LEVEL1       0x649
#define MSR_CONFIG_TDP_LEVEL2       0x64A
#define MSR_CONFIG_TDP_CONTROL      0x64B  /* write once to lock */
#define MSR_TURBO_ACTIVATION_RATIO  0x64C

//Skylake
#define BASE_ART_CLOCK_SOURCE   24000000ULL  /* 24Mhz */
#define MSR_IA32_PM_ENABLE          0x770
#define MSR_IA32_HWP_REQUEST        0x774

//AMD
#define K8_FIDVID_STATUS            0xC0010042
#define K10_COFVID_LIMIT            0xC0010061 /* max enabled p-state (msr >> 4) & 7 */
#define K10_COFVID_CONTROL          0xC0010062 /* switch to p-state */
#define K10_PSTATE_STATUS           0xC0010064
#define K10_COFVID_STATUS           0xC0010071 /* current p-state (msr >> 16) & 7 */
/* specific settings
static void SavePState(unsigned int index, unsigned int lowMsr, unsigned int core)
{
  CONST unsigned int msrIndex = 0xC0010064u + index;
  CONST DWORD_PTR affinityMask = (DWORD_PTR)1 << core;

  DWORD lower, higher;
  RdmsrTx(msrIndex, &lower, &higher, affinityMask);

  CONST DWORD lowMsrMask = 0xFE40FFFFu;
  lower = (lower & ~lowMsrMask) | (lowMsr & lowMsrMask);

  WrmsrTx(msrIndex, lower, higher, affinityMask);
}

MSR C0010064  8000-0185-0000-1418 [20.00x] [1.4250 V] [13.30 A] [PState Pb0]
MSR C0010065  8000-0185-0000-1615 [18.50x] [1.4125 V] [13.30 A] [PState Pb1]
MSR C0010066  8000-0173-0000-1A1A [21.00x] [1.3875 V] [11.50 A] [PState P0]
MSR C0010067  0000-0173-0000-1A1A
MSR C0010068  0000-0173-0000-181A
MSR C0010069  0000-0173-0000-1A1A
MSR C001006A  8000-0125-0000-604C [ 7.00x] [0.9500 V] [ 3.70 A] [PState P1]
MSR C001006B  0000-0000-0000-0000
*/


#define DEFAULT_FSB                 100000          /* for now, hardcoding 100MHz for old CPUs */


/* CPUID Index */
#define CPUID_0    0
#define CPUID_1    1
#define CPUID_2    2
#define CPUID_3    3
#define CPUID_4    4
#define CPUID_5    5
#define CPUID_6    6
#define CPUID_80   7
#define CPUID_81   8
#define CPUID_87   9
#define CPUID_88   10
#define CPUID_81E  11
#define CPUID_15   15
#define CPUID_MAX  16

/* CPU Cache */
#define MAX_CACHE_COUNT  4
#define CPU_CACHE_LEVEL  3

/* PCI */
#define PCI_BASE_ADDRESS_0          0x10    /* 32 bits */
#define PCI_BASE_ADDRESS_1          0x14    /* 32 bits [htype 0,1 only] */
#define PCI_BASE_ADDRESS_2          0x18    /* 32 bits [htype 0 only] */
#define PCI_BASE_ADDRESS_3          0x1c    /* 32 bits */
#define PCI_BASE_ADDRESS_4          0x20    /* 32 bits */
#define PCI_BASE_ADDRESS_5          0x24    /* 32 bits */

#define PCI_CLASS_MEDIA_HDA         0x03

#define GEN_PMCON_1                 0xA0

#define PCIADDR(bus, dev, func)      ((1 << 31) | ((bus) << 16) | ((dev) << 11) | ((func) << 8))
#define REG8(base, reg)              ((volatile UINT8 *)(UINTN)(base))[(reg)]
#define REG16(base, reg)             ((volatile UINT16 *)(UINTN)(base))[(reg) >> 1]
//#define REG32(base, reg)             ((volatile UINT32 *)(UINTN)(base))[(reg) >> 2]
#define REG32(base, reg)             (*(volatile UINT32 *)((UINTN)base + reg))
#define WRITEREG32(base, reg, value) REG32((base), (reg)) = value

#define EFI_HANDLE_TYPE_UNKNOWN                     0x000
#define EFI_HANDLE_TYPE_IMAGE_HANDLE                0x001
#define EFI_HANDLE_TYPE_DRIVER_BINDING_HANDLE       0x002
#define EFI_HANDLE_TYPE_DEVICE_DRIVER               0x004
#define EFI_HANDLE_TYPE_BUS_DRIVER                  0x008
#define EFI_HANDLE_TYPE_DRIVER_CONFIGURATION_HANDLE 0x010
#define EFI_HANDLE_TYPE_DRIVER_DIAGNOSTICS_HANDLE   0x020
#define EFI_HANDLE_TYPE_COMPONENT_NAME_HANDLE       0x040
#define EFI_HANDLE_TYPE_DEVICE_HANDLE               0x080
#define EFI_HANDLE_TYPE_PARENT_HANDLE               0x100
#define EFI_HANDLE_TYPE_CONTROLLER_HANDLE           0x200
#define EFI_HANDLE_TYPE_CHILD_HANDLE                0x400

#define  AML_CHUNK_NONE          0xff
#define  AML_CHUNK_ZERO          0x00
#define  AML_CHUNK_ONE           0x01
#define  AML_CHUNK_ALIAS         0x06
#define  AML_CHUNK_NAME          0x08
#define  AML_CHUNK_BYTE          0x0A
#define  AML_CHUNK_WORD          0x0B
#define  AML_CHUNK_DWORD         0x0C
#define  AML_CHUNK_STRING        0x0D
#define  AML_CHUNK_QWORD         0x0E
#define  AML_CHUNK_SCOPE         0x10
#define  AML_CHUNK_PACKAGE       0x12
#define  AML_CHUNK_METHOD        0x14
#define AML_CHUNK_RETURN         0xA4
#define AML_LOCAL0               0x60
#define AML_STORE_OP             0x70
//-----------------------------------
// defines added by pcj
#define  AML_CHUNK_BUFFER        0x11
#define  AML_CHUNK_STRING_BUFFER 0x15
#define  AML_CHUNK_OP            0x5B
#define  AML_CHUNK_REFOF         0x71
#define  AML_CHUNK_DEVICE        0x82
#define  AML_CHUNK_LOCAL0        0x60
#define  AML_CHUNK_LOCAL1        0x61
#define  AML_CHUNK_LOCAL2        0x62

#define  AML_CHUNK_ARG0          0x68
#define  AML_CHUNK_ARG1          0x69
#define  AML_CHUNK_ARG2          0x6A
#define  AML_CHUNK_ARG3          0x6B

//DSDT fixes MASK
//0x00FF
#define FIX_DTGP      bit(0)
#define FIX_WARNING   bit(1)
#define FIX_SHUTDOWN  bit(2)
#define FIX_MCHC      bit(3)
#define FIX_HPET      bit(4)
#define FIX_LPC       bit(5)
#define FIX_IPIC      bit(6)
#define FIX_SBUS      bit(7)
//0xFF00
#define FIX_DISPLAY   bit(8)
#define FIX_IDE       bit(9)
#define FIX_SATA      bit(10)
#define FIX_FIREWIRE  bit(11)
#define FIX_USB       bit(12)
#define FIX_LAN       bit(13)
#define FIX_WIFI      bit(14)
#define FIX_HDA       bit(15)
//new bits 16-31 0xFFFF0000
//#define FIX_NEW_WAY   bit(31) will be reused
#define FIX_DARWIN    bit(16)
#define FIX_RTC       bit(17)
#define FIX_TMR       bit(18)
#define FIX_IMEI      bit(19)
#define FIX_INTELGFX  bit(20)
#define FIX_WAK       bit(21)
#define FIX_UNUSED    bit(22)
#define FIX_ADP1      bit(23)
#define FIX_PNLF      bit(24)
#define FIX_S3D       bit(25)
#define FIX_ACST      bit(26)
#define FIX_HDMI      bit(27)
#define FIX_REGIONS   bit(28)
#define FIX_HEADERS   bit(29)
#define FIX_MUTEX     bit(30)

//devices
#define DEV_ATI       bit(0)
#define DEV_NVIDIA    bit(1)
#define DEV_INTEL     bit(2)
#define DEV_HDA       bit(3)
#define DEV_HDMI      bit(4)
#define DEV_LAN       bit(5)
#define DEV_WIFI      bit(6)
#define DEV_SATA      bit(7)
#define DEV_IDE       bit(8)
#define DEV_LPC       bit(9)
#define DEV_SMBUS     bit(10)
#define DEV_USB       bit(11)
#define DEV_FIREWIRE  bit(12)
#define DEV_MCHC      bit(13)
#define DEV_IMEI      bit(14)
#define DEV_BY_PCI    bit(31)

#define NUM_OF_CONFIGS 3

// Kernel scan states
#define KERNEL_SCAN_ALL        (0)
#define KERNEL_SCAN_NEWEST     (1)
#define KERNEL_SCAN_OLDEST     (2)
#define KERNEL_SCAN_FIRST      (3)
#define KERNEL_SCAN_LAST       (4)
#define KERNEL_SCAN_MOSTRECENT (5)
#define KERNEL_SCAN_EARLIEST   (6)
#define KERNEL_SCAN_NONE       (100)

// Secure boot policies
// Deny all images
#define SECURE_BOOT_POLICY_DENY      (0)
// Allow all images
#define SECURE_BOOT_POLICY_ALLOW     (1)
// Query the user to choose action
#define SECURE_BOOT_POLICY_QUERY     (2)
// Insert signature into db
#define SECURE_BOOT_POLICY_INSERT    (3)
// White list
#define SECURE_BOOT_POLICY_WHITELIST (4)
// Black list
#define SECURE_BOOT_POLICY_BLACKLIST (5)
// User policy, white and black list with query
#define SECURE_BOOT_POLICY_USER      (6)



#include "BootLog.h"


#endif
