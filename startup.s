.syntax unified
.thumb
.global reset_handler
.global NMI_handler
.global hardfault_handler
.global memmanage_handler
.global busfault_handler
.global usagefault_handler
.global svc_handler
.global debug_monitor_handler
.global pendSV_handler
.global Systick_handler

.section .isr_vector
    .thumb_func
    .word _stack_start
    .word reset_handler
    .word NMI_handler
    .word hardfault_handler
    .word memmanage_handler
    .word busfault_handler
    .word usagefault_handler
    .word 0
    .word 0
    .word 0
    .word 0
    .word svc_handler
    .word debug_monitor_handler
    .word 0
    .word pendSV_handler
    .word Systick_handler

.type reset_handler , %function
reset_handler:
    .thumb_func
    bl sys_init
    bl main

.type NMI_handler ,%function
NMI_handler :
    b .
.type hardfault_handler , %function
hardfault_handler :
    b .

.type memmanage_handler , %function
memmanage_handler :
    b .

.type busfault_handler , %function
busfault_handler :
    b .

.type usagefault_handler , %function
usagefault_handler :
    b .

.type svc_handler , %function
svc_handler :
    b .

.type debug_monitor_handler , %function
debug_monitor_handler :
    b .

.type pendSV_handler , %function
pendSV_handler :
    b .

.type Systick_handler , %function
Systick_handler :
    b .

.type sys_init ,%function
sys_init :
    ldr r0, = _load_data_start
    ldr r1, = _start_of_data
    ldr r2, = _end_of_data 
    ldr r4, = _start_of_bss
    ldr r5, = _end_of_bss
init_data: 
    cmp r1,r2
    bge copy_done
    ldr r3 , [r0] , #4
    str r3 , [r1] , #4

    b init_data
copy_done:  
init_bss :
    cmp r4,r5
    bge done
    movs r6,#0
    str r6, [r4] ,#4

    b init_bss
done:
    bx lr



