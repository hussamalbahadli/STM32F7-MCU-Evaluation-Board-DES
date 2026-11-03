# STM32F7-MCU-Evaluation-Board-DES

Bare-metal drivers written from scratch for the **STM32F746ZG** on a **NUCLEO-F746ZG** board, following the same layered architecture and naming conventions I use in my AVR and STM32F103 repositories.

> Personal training repository. Every driver is written by hand from the Reference Manual (RM0385) — no HAL, no CubeMX-generated code.

---

## Architecture

```
Driver/
 ├── LIB/            Generic types and macros — identical across MCUs
 ├── MCAL/           Hardware layer: touches registers directly
 │    ├── RCC/
 │    ├── GPIO/
 │    └── STK/
 ├── HAL/            Higher layer: uses MCAL, knows no registers
 └── SERVICES/       Generic services (scheduler, filters, ...)
```

Every driver consists of **four files**:

| File | Role |
|---|---|
| `X_interface.h` | The contract — what the user is allowed to do |
| `X_private.h` | Register addresses and bit positions |
| `X_config.h` | Build-time options the user edits |
| `X_program.c` | Implementation |

### Naming conventions
- Function parameters: `Copy_u8...`
- Local variables: `Local_u8...`
- Functions: `MODULE_voidName` / `MODULE_u8Name`

---

## Status

| Driver | Status |
|---|---|
| LIB | Done |
| RCC | Not started |
| GPIO | Not started |
| STK | Not started |

---

## Why the F103 GPIO driver cannot be reused

The STM32F103 GPIO driver **will not work here at all**. This is not a small patch — the register model is completely different:

| F103 (Cortex-M3) | F746 (Cortex-M7) |
|---|---|
| `CRL` / `CRH` — 4 bits per pin | `MODER` — 2 bits per pin |
| Those 4 bits encode mode + type + speed together | Split into `MODER` + `OTYPER` + `OSPEEDR` + `PUPDR` |
| GPIO clock on `APB2ENR` | GPIO clock on `AHB1ENR` |

**But `GPIO_interface.h` stays byte-for-byte identical.** That is the entire point of the layered architecture: `Example/01_GPIO_Blink/main.c` compiles and runs unchanged on both MCUs.

---

## Board quick reference

| Signal | Pin |
|---|---|
| LD1 (green) | PB0 |
| LD2 (blue) | PB7 |
| LD3 (red) | PB14 |
| User button | PC13 |
| ST-LINK VCP (serial over USB) | USART3 — PD8 / PD9 |

HSI = 16 MHz · HSE from ST-LINK MCO = 8 MHz · Max core clock = 216 MHz

---

## Build

Keil MDK-ARM (uVision 5). Add `Driver/LIB`, `Driver/MCAL/*` and the example folder to the include paths. Flash over the on-board ST-LINK.

`Example/01_GPIO_Blink/main.c` is the acceptance test — it is never modified. Write `RCC` and `GPIO` until it runs as-is.

---

## References

- **RM0385** — Reference Manual (STM32F74x/75x)
- **DS10916** — Datasheet (STM32F746ZG)
- **UM1974** — Nucleo-144 board user manual
- **PM0253** — Cortex-M7 Programming Manual
