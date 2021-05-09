shared_flags = [
            '-O2',
            '-MMD',
            '-Wno-format',
            '-Wall',
            '-Werror',
            '-std=c++17',
            '-ggdb3',
            ]
env = Environment(
        CPPDEFINES = {
            '__DIFF_REF_QEMU__': None,
            'XIANGSHAN': 1,
            # 'SHARE': 1,
            },
        CC = 'g++',
        CXX = 'g++',
        CPPPATH = [
            './include',
            './src/engine/interpreter',
            './src/isa/riscv64/softfloat',
            './resource',
            '/usr/include',
            ],
        CXXFLAGS = shared_flags,
        CFLAGS = shared_flags,
        )
env.Append(CPPDEFINES = {

    '__ENGINE_interpreter__': None,
    '__SIMPOINT': None,
    '__GCPT_COMPATIBLE__': None,
    '__ISA__': 'riscv64',
    '__ISA_riscv64__': None,
    '_ISA_H_': '\\"isa/riscv64.h\\"',
    })
sources = [
'./src/main.c',
'./src/device/vga.c',
'./src/device/alarm.c',
'./src/device/uartlite.c',
'./src/device/intr.c',
'./src/device/device.c',
'./src/device/audio.c',
'./src/device/io/mmio.c',
'./src/device/io/map.c',
'./src/device/io/port-io.c',
'./src/device/sdcard.c',
'./src/device/serial.c',
'./src/device/keyboard.c',
'./src/device/timer.c',
'./src/isa/riscv64/logo.c',
'./src/isa/riscv64/init.c',
'./src/isa/riscv64/exec/exec.c',
'./src/isa/riscv64/exec/special.c',
'./src/isa/riscv64/difftest/ref.c',
'./src/isa/riscv64/difftest/dut.c',

'./src/isa/riscv64/reg.c',
'./src/isa/riscv64/mmu.c',
'./src/isa/riscv64/intr.c',
'./src/isa/riscv64/clint.c',
'./src/monitor/cpu-exec.c',
'./src/monitor/monitor.c',
'./src/monitor/difftest/ref.c',
'./src/monitor/difftest/dut.c',
'./src/monitor/debug/expr.c',
'./src/monitor/debug/ui.c',
'./src/monitor/debug/watchpoint.c',
'./src/monitor/debug/log.c',
'./src/memory/paddr.c',
'./src/memory/vaddr.c',
'./src/engine/interpreter/init.c',
'./src/checkpoint/profiler.cpp',
'./src/checkpoint/serializer.cpp',
'./src/checkpoint/path_manager.cpp',
'./src/checkpoint/simpoint.cpp',
'./src/iostream3/zfstream.cpp',
'./src/base/output.cpp',
]

softfloat_srcs = [
        './src/isa/riscv64/softfloat/f16_rem.c',
        './src/isa/riscv64/softfloat/s_subMagsF32.c',
        './src/isa/riscv64/softfloat/f32_to_ui32_r_minMag.c',
        './src/isa/riscv64/softfloat/f128_to_ui64_r_minMag.c',
        './src/isa/riscv64/softfloat/f64_to_ui64.c',
        './src/isa/riscv64/softfloat/s_roundPackToF128.c',
        './src/isa/riscv64/softfloat/s_mulAddF64.c',
        './src/isa/riscv64/softfloat/s_commonNaNToF32UI.c',
        './src/isa/riscv64/softfloat/s_add128.c',
        './src/isa/riscv64/softfloat/f32_isSignalingNaN.c',
        './src/isa/riscv64/softfloat/f16_to_f32.c',
        './src/isa/riscv64/softfloat/f128_sub.c',
        './src/isa/riscv64/softfloat/f16_lt_quiet.c',
        './src/isa/riscv64/softfloat/f64_roundToInt.c',
        './src/isa/riscv64/softfloat/s_roundPackToF64.c',
        './src/isa/riscv64/softfloat/f32_le.c',
        './src/isa/riscv64/softfloat/s_f32UIToCommonNaN.c',
        './src/isa/riscv64/softfloat/s_mul64ByShifted32To128.c',
        './src/isa/riscv64/softfloat/f32_classify.c',
        './src/isa/riscv64/softfloat/s_shortShiftLeft64To96M.c',
        './src/isa/riscv64/softfloat/s_shortShiftLeft128.c',
        './src/isa/riscv64/softfloat/s_subMagsF16.c',
        './src/isa/riscv64/softfloat/f16_le_quiet.c',
        './src/isa/riscv64/softfloat/f16_add.c',
        './src/isa/riscv64/softfloat/f128_le.c',
        './src/isa/riscv64/softfloat/s_sub1XM.c',
        './src/isa/riscv64/softfloat/s_addCarryM.c',
        './src/isa/riscv64/softfloat/f32_to_i64_r_minMag.c',
        './src/isa/riscv64/softfloat/f64_to_i64_r_minMag.c',
        './src/isa/riscv64/softfloat/f16_sqrt.c',
        './src/isa/riscv64/softfloat/ui32_to_f16.c',
        './src/isa/riscv64/softfloat/f16_to_i32_r_minMag.c',
        './src/isa/riscv64/softfloat/i32_to_f16.c',
        './src/isa/riscv64/softfloat/s_shiftRightJam128Extra.c',
        './src/isa/riscv64/softfloat/f16_to_ui32_r_minMag.c',
        './src/isa/riscv64/softfloat/s_eq128.c',
        './src/isa/riscv64/softfloat/s_addMagsF128.c',
        './src/isa/riscv64/softfloat/s_commonNaNToF128UI.c',
        './src/isa/riscv64/softfloat/f16_to_i32.c',
        './src/isa/riscv64/softfloat/s_shortShiftRightJam128Extra.c',
        './src/isa/riscv64/softfloat/s_roundPackToI64.c',
        './src/isa/riscv64/softfloat/f64_lt_quiet.c',
        './src/isa/riscv64/softfloat/s_shortShiftRightJam128.c',
        './src/isa/riscv64/softfloat/s_mulAddF16.c',
        './src/isa/riscv64/softfloat/f128_roundToInt.c',
        './src/isa/riscv64/softfloat/s_shiftRightJam64.c',
        './src/isa/riscv64/softfloat/s_compare96M.c',
        './src/isa/riscv64/softfloat/f16_roundToInt.c',
        './src/isa/riscv64/softfloat/s_normSubnormalF64Sig.c',
        './src/isa/riscv64/softfloat/f32_lt.c',
'./src/isa/riscv64/softfloat/s_normSubnormalF16Sig.c',
'./src/isa/riscv64/softfloat/f16_isSignalingNaN.c',
'./src/isa/riscv64/softfloat/s_addM.c',
'./src/isa/riscv64/softfloat/s_shiftRightJam32.c',
'./src/isa/riscv64/softfloat/s_f16UIToCommonNaN.c',
'./src/isa/riscv64/softfloat/f64_to_i32_r_minMag.c',
'./src/isa/riscv64/softfloat/f32_to_ui64.c',
'./src/isa/riscv64/softfloat/s_mul128MTo256M.c',
'./src/isa/riscv64/softfloat/i32_to_f128.c',
'./src/isa/riscv64/softfloat/s_addMagsF16.c',
'./src/isa/riscv64/softfloat/f32_to_i32.c',
'./src/isa/riscv64/softfloat/s_normRoundPackToF128.c',
'./src/isa/riscv64/softfloat/f128_le_quiet.c',
'./src/isa/riscv64/softfloat/f128_to_ui32.c',
'./src/isa/riscv64/softfloat/f32_to_ui64_r_minMag.c',
'./src/isa/riscv64/softfloat/f32_to_f16.c',
'./src/isa/riscv64/softfloat/i64_to_f64.c',
'./src/isa/riscv64/softfloat/s_normRoundPackToF16.c',
'./src/isa/riscv64/softfloat/ui32_to_f128.c',
'./src/isa/riscv64/softfloat/s_normSubnormalF128Sig.c',
'./src/isa/riscv64/softfloat/s_roundPackMToUI64.c',
'./src/isa/riscv64/softfloat/f128_to_ui32_r_minMag.c',
'./src/isa/riscv64/softfloat/ui64_to_f64.c',
'./src/isa/riscv64/softfloat/s_roundToI64.c',
'./src/isa/riscv64/softfloat/s_shortShiftRightExtendM.c',
'./src/isa/riscv64/softfloat/f64_to_i64.c',
'./src/isa/riscv64/softfloat/f16_sub.c',
'./src/isa/riscv64/softfloat/f16_le.c',
'./src/isa/riscv64/softfloat/f64_mulAdd.c',
'./src/isa/riscv64/softfloat/s_roundPackToF32.c',
'./src/isa/riscv64/softfloat/s_roundPackMToI64.c',
'./src/isa/riscv64/softfloat/s_le128.c',
'./src/isa/riscv64/softfloat/f32_div.c',
'./src/isa/riscv64/softfloat/f128_to_f64.c',
'./src/isa/riscv64/softfloat/s_mul128By32.c',
'./src/isa/riscv64/softfloat/f128_lt_quiet.c',
'./src/isa/riscv64/softfloat/f16_to_i64.c',
'./src/isa/riscv64/softfloat/f64_add.c',
'./src/isa/riscv64/softfloat/f64_to_f128.c',
'./src/isa/riscv64/softfloat/ui64_to_f128.c',
'./src/isa/riscv64/softfloat/f16_lt.c',
'./src/isa/riscv64/softfloat/i64_to_f128.c',
'./src/isa/riscv64/softfloat/f32_to_ui32.c',
'./src/isa/riscv64/softfloat/s_commonNaNToF64UI.c',
'./src/isa/riscv64/softfloat/f64_sub.c',
'./src/isa/riscv64/softfloat/s_add256M.c',
'./src/isa/riscv64/softfloat/ui64_to_f32.c',
'./src/isa/riscv64/softfloat/f64_to_ui32_r_minMag.c',
'./src/isa/riscv64/softfloat/i64_to_f16.c',
'./src/isa/riscv64/softfloat/f16_mulAdd.c',
'./src/isa/riscv64/softfloat/f32_eq.c',
'./src/isa/riscv64/softfloat/f16_to_ui32.c',
'./src/isa/riscv64/softfloat/f128_isSignalingNaN.c',
'./src/isa/riscv64/softfloat/softfloat_state.c',
'./src/isa/riscv64/softfloat/s_compare128M.c',
'./src/isa/riscv64/softfloat/s_propagateNaNF16UI.c',
'./src/isa/riscv64/softfloat/f128_rem.c',
'./src/isa/riscv64/softfloat/f32_sqrt.c',
'./src/isa/riscv64/softfloat/f32_eq_signaling.c',
'./src/isa/riscv64/softfloat/f16_to_f64.c',
'./src/isa/riscv64/softfloat/s_approxRecip_1Ks.c',
'./src/isa/riscv64/softfloat/s_propagateNaNF128UI.c',
'./src/isa/riscv64/softfloat/f64_to_ui32.c',
'./src/isa/riscv64/softfloat/f32_mul.c',
'./src/isa/riscv64/softfloat/s_shiftRightJam64Extra.c',
'./src/isa/riscv64/softfloat/f32_to_f128.c',
'./src/isa/riscv64/softfloat/f128_mul.c',
'./src/isa/riscv64/softfloat/f64_to_f32.c',
'./src/isa/riscv64/softfloat/f128_to_i32.c',
'./src/isa/riscv64/softfloat/s_approxRecip32_1.c',
'./src/isa/riscv64/softfloat/f128_eq.c',
'./src/isa/riscv64/softfloat/i64_to_f32.c',
'./src/isa/riscv64/softfloat/f16_to_i64_r_minMag.c',
'./src/isa/riscv64/softfloat/s_countLeadingZeros64.c',
'./src/isa/riscv64/softfloat/s_lt128.c',
'./src/isa/riscv64/softfloat/s_subM.c',
'./src/isa/riscv64/softfloat/s_normRoundPackToF64.c',
'./src/isa/riscv64/softfloat/s_roundToUI64.c',
'./src/isa/riscv64/softfloat/f16_mul.c',
'./src/isa/riscv64/softfloat/ui32_to_f32.c',
'./src/isa/riscv64/softfloat/softfloat_raiseFlags.c',
'./src/isa/riscv64/softfloat/f32_add.c',
'./src/isa/riscv64/softfloat/f64_le.c',
'./src/isa/riscv64/softfloat/s_roundPackToI32.c',
'./src/isa/riscv64/softfloat/f16_eq.c',
'./src/isa/riscv64/softfloat/s_countLeadingZeros16.c',
'./src/isa/riscv64/softfloat/s_shortShiftRightJam64Extra.c',
'./src/isa/riscv64/softfloat/s_shortShiftRight128.c',
'./src/isa/riscv64/softfloat/s_roundPackToUI64.c',
'./src/isa/riscv64/softfloat/s_subMagsF64.c',
'./src/isa/riscv64/softfloat/f32_rem.c',
'./src/isa/riscv64/softfloat/s_propagateNaNF64UI.c',
'./src/isa/riscv64/softfloat/s_mul128To256M.c',
'./src/isa/riscv64/softfloat/f128_to_ui64.c',
'./src/isa/riscv64/softfloat/f16_to_ui64_r_minMag.c',
'./src/isa/riscv64/softfloat/s_roundToUI32.c',
'./src/isa/riscv64/softfloat/f128_div.c',
'./src/isa/riscv64/softfloat/f64_le_quiet.c',
'./src/isa/riscv64/softfloat/f64_eq.c',
'./src/isa/riscv64/softfloat/f128_to_i64.c',
'./src/isa/riscv64/softfloat/s_sub256M.c',
'./src/isa/riscv64/softfloat/f64_eq_signaling.c',
'./src/isa/riscv64/softfloat/f64_lt.c',
'./src/isa/riscv64/softfloat/ui64_to_f16.c',
'./src/isa/riscv64/softfloat/s_roundMToI64.c',
'./src/isa/riscv64/softfloat/f32_to_f64.c',
'./src/isa/riscv64/softfloat/s_subMagsF128.c',
'./src/isa/riscv64/softfloat/f64_sqrt.c',
'./src/isa/riscv64/softfloat/s_mulAddF32.c',
'./src/isa/riscv64/softfloat/s_f128UIToCommonNaN.c',
'./src/isa/riscv64/softfloat/s_roundMToUI64.c',
'./src/isa/riscv64/softfloat/s_remStepMBy32.c',
'./src/isa/riscv64/softfloat/f32_roundToInt.c',
'./src/isa/riscv64/softfloat/i32_to_f64.c',
'./src/isa/riscv64/softfloat/f128_add.c',
'./src/isa/riscv64/softfloat/s_negXM.c',
'./src/isa/riscv64/softfloat/f64_div.c',
'./src/isa/riscv64/softfloat/f64_rem.c',
'./src/isa/riscv64/softfloat/f128_eq_signaling.c',
'./src/isa/riscv64/softfloat/s_shiftRightJam256M.c',
'./src/isa/riscv64/softfloat/f64_mul.c',
'./src/isa/riscv64/softfloat/f32_lt_quiet.c',
'./src/isa/riscv64/softfloat/f64_to_ui64_r_minMag.c',
'./src/isa/riscv64/softfloat/f32_le_quiet.c',
'./src/isa/riscv64/softfloat/i32_to_f32.c',
'./src/isa/riscv64/softfloat/s_shiftRightJam128.c',
'./src/isa/riscv64/softfloat/f64_isSignalingNaN.c',
'./src/isa/riscv64/softfloat/f64_to_i32.c',
'./src/isa/riscv64/softfloat/s_roundToI32.c',
'./src/isa/riscv64/softfloat/s_shortShiftRightM.c',
'./src/isa/riscv64/softfloat/f16_to_ui64.c',
'./src/isa/riscv64/softfloat/s_commonNaNToF16UI.c',
'./src/isa/riscv64/softfloat/f32_sub.c',
'./src/isa/riscv64/softfloat/f64_to_f16.c',
'./src/isa/riscv64/softfloat/s_addMagsF32.c',
'./src/isa/riscv64/softfloat/s_approxRecipSqrt_1Ks.c',
'./src/isa/riscv64/softfloat/f128_to_i64_r_minMag.c',
'./src/isa/riscv64/softfloat/f32_to_i64.c',
'./src/isa/riscv64/softfloat/f32_mulAdd.c',
'./src/isa/riscv64/softfloat/s_roundPackToUI32.c',
'./src/isa/riscv64/softfloat/s_approxRecipSqrt32_1.c',
'./src/isa/riscv64/softfloat/s_mul64To128.c',
'./src/isa/riscv64/softfloat/s_addComplCarryM.c',
'./src/isa/riscv64/softfloat/f128_classify.c',
'./src/isa/riscv64/softfloat/f128_lt.c',
'./src/isa/riscv64/softfloat/s_normSubnormalF32Sig.c',
'./src/isa/riscv64/softfloat/s_addMagsF64.c',
'./src/isa/riscv64/softfloat/s_countLeadingZeros8.c',
'./src/isa/riscv64/softfloat/f128_to_f16.c',
'./src/isa/riscv64/softfloat/ui32_to_f64.c',
'./src/isa/riscv64/softfloat/s_f64UIToCommonNaN.c',
'./src/isa/riscv64/softfloat/f64_classify.c',
'./src/isa/riscv64/softfloat/f128_mulAdd.c',
'./src/isa/riscv64/softfloat/s_shortShiftRightJam64.c',
'./src/isa/riscv64/softfloat/s_mulAddF128.c',
'./src/isa/riscv64/softfloat/s_roundPackToF16.c',
'./src/isa/riscv64/softfloat/s_countLeadingZeros32.c',
'./src/isa/riscv64/softfloat/f32_to_i32_r_minMag.c',
'./src/isa/riscv64/softfloat/s_sub128.c',
'./src/isa/riscv64/softfloat/f128_to_f32.c',
'./src/isa/riscv64/softfloat/f16_to_f128.c',
'./src/isa/riscv64/softfloat/f16_eq_signaling.c',
'./src/isa/riscv64/softfloat/s_normRoundPackToF32.c',
'./src/isa/riscv64/softfloat/f128_sqrt.c',
'./src/isa/riscv64/softfloat/s_mul64To128M.c',
'./src/isa/riscv64/softfloat/f16_div.c',
'./src/isa/riscv64/softfloat/s_propagateNaNF32UI.c',
'./src/isa/riscv64/softfloat/f128_to_i32_r_minMag.c',
        ]
softfloat_objs = env.Object(softfloat_srcs,
        CXXFLAGS = shared_flags + ['-w', '-fPIC'],
        CFLAGS = shared_flags + ['-w', '-fPIC'],
        )

env.Program([*sources, *softfloat_objs], LIBS=['dl', 'SDL2', 'readline', 'z'])
