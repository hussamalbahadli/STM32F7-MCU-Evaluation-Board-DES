# RM0385 Notes — STM32F746ZG

> **Reference Manual:** RM0385 Rev 8 — STM32F75xxx / STM32F74xxx
> **Datasheet:** DS10916 — STM32F746ZG
> **Board:** NUCLEO-F746ZG (UM1974)

Page number + register name + what I understood from it. Written in my own words, not copied from the manual.

---

## Modules

| Module | RM section / page | Key registers | My notes |
|---|---|---|---|
| RCC | §5.3 RCC registers — p.145<br>Register map: Table 21 — p.198 | `RCC_CR`, `RCC_CFGR`, `RCC_AHB1ENR` | Base address `0x4002 3800` (range up to `0x4002 3BFF`), from the memory map — p.71 |
| GPIO |  |  |  |
| SysTick |  |  |  |

---

## Where things are in RM0385

| What | Page |
|---|---|
| Memory map — register boundary addresses (peripheral base addresses) | p.71 |
| RCC registers (§5.3) | p.145 |
| Table 21 — RCC register map and reset values | p.198 |

---

## RCC — what the first driver version needs

Only what `Example/01_GPIO_Blink` uses. Everything else waits for the 216 MHz version.

| Register | Bits I need | Purpose |
|---|---|---|
| `RCC_CR` | `HSION` (0), `HSIRDY` (1) | Turn on HSI and wait until it is ready |
| `RCC_CFGR` | `SW` (1:0), `SWS` (3:2) | Select HSI as SYSCLK and confirm the switch |
| `RCC_AHB1ENR` | `GPIOAEN` … `GPIOKEN` (0–10) | Enable GPIO port clocks |

**Skipped for now:** PLL / PLLI2S / PLLSAI, HSE + CSS, LSE / LSI / backup domain, reset (`…RSTR`) and low-power (`…LPENR`) registers, `RCC_CIR`, `DCKCFGR`.

**F7 note:** after enabling a peripheral clock, do a dummy read of the same register before touching the peripheral.

---

## Board facts

| Item | Value |
|---|---|
| LD1 (green) | PB0 |
| LD2 (blue) | PB7 |
| LD3 (red) | PB14 |
| User button (blue) | PC13 |
| ST-LINK VCP | USART3 → PD8 (TX) / PD9 (RX) |
| HSI | 16 MHz |
| HSE (from ST-LINK MCO) | 8 MHz |
| Max core clock | 216 MHz |
