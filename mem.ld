/* Memory layout for the STM32F407 */

/* Entry Point
* Doesn't really matter but informative for debuggers,etc
*/
ENTRY(Reset_Handler)

MEMORY {
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
  RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 128K
  CCMRAM (rw) : ORIGIN = 0x10000000, LENGTH = 64K
}


/* Highest address of the user mode stack */
_estack = 0x20020000;    /* end of RAM */

/* Output Sectons */
SECTIONS {
  .isr_vector : {
    /*Insert ISR vector table first*/
     . = ALIGN(4);
    /* Vector table needs to be word aligned, next address that would be
     * word aligned is 512
    */
    KEEP(*(.isr_vector))
     . = ALIGN(4);
  } > FLASH = 0xEE

  /* Text section (code and read-only data)*/
  .text : {
    /* test section (code) */
    *(.text)
    *(.text*)
    . = ALIGN(4);
  } > FLASH

  .rodata :  {
     . = ALIGN(4);

    /* .rodata sections (constants) */
    *(.rodata)

    /* .rodata* sections (strings, etc.) */
    *(.rodata*)
     . = ALIGN(4);
  } > FLASH

  /* Used by the startup to initialize data */
  /* this contains the LMA of the data section */
  _sidata=LOADADDR(.data);

  .data : ALIGN(4) {
    . = ALIGN(4);
    _sdata = .; /* create a global symbol at data start */

    *(.data)
    *(.data*)

    . = ALIGN(4);
    _edata = .;
  } > RAM AT>FLASH



  .bss (NOLOAD)  : ALIGN(4) {
    /* This is used by the startup in order to initialize the .bss section */
    _sbss = .; /* define a global symbol at bss start */
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    /* define a global symbol at bss end */
    _ebss = .;
    PROVIDE(_start_heap = .);
  } >RAM
}

PROVIDE(_end_heap = ORIGIN(RAM) + LENGTH(RAM));
/*
 * Necessary group so the newlib stubs provided in the library,
 * will correctly be linked with the appropriate newlib functions,
 * and not optimized out, giving errors for undefined symbols.
 * This way the libraries can be fed to the linker in any order.
 */
GROUP(
   libgcc.a
   libg.a
   libc.a
   libm.a
   libnosys.a
 )
