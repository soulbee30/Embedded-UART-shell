MEMORY
{
    FLASH : ORIGIN = 0x08000000 , LENGTH = 512K
    RAM : ORIGIN = 0x20000000 , LENGTH = 128K
}
_stack_start = ORIGIN(RAM) + LENGTH(RAM);
SECTIONS
{
    .text :
    {
        _start_of_text = .;
        *(.isr_vector)
        *(.text*)
        _end_of_text = .;
    } > FLASH
    .rodata :
    {
        _start_of_rodata = .;
        *(.rodata)
        _end_of_rodata = .;
    } > FLASH
    .data :
    {

        _start_of_data = .;
        *(.data)
        _end_of_data = .;  
    } > RAM AT > FLASH
    _load_data_start = LOADADDR(.data);
    .bss :
    {
        _start_of_bss = .;
        *(.bss)
        _end_of_bss = .;
    } > RAM
}