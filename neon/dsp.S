.text
.arch armv7-a
.fpu neon
.syntax unified

.global add_dc
add_dc:
        vld1.16         {d0[], d1[]}, [r2,:16]
        vmov.s16        q1, #3
        vmul.s16        q2, q0, q1
        vrshr.s16       q3, q2, #1
        vmul.s16        q4, q3, q1
        vrshr.s16       q0, q4, #5
        
        mov             r3, r0

        vld1.8          {d2}, [r0], r1   
        vaddw.u8        q2,  q0,  d2
        vqmovun.s16     d3,  q2      
        vst1.8          {d3}, [r3], r1

        vld1.8          {d2}, [r0], r1   
        vaddw.u8        q2,  q0,  d2
        vqmovun.s16     d3,  q2      
        vst1.8          {d3}, [r3], r1

        vld1.8          {d2}, [r0], r1   
        vaddw.u8        q2,  q0,  d2
        vqmovun.s16     d3,  q2      
        vst1.8          {d3}, [r3], r1

        vld1.8          {d2}, [r0], r1   
        vaddw.u8        q2,  q0,  d2
        vqmovun.s16     d3,  q2      
        vst1.8          {d3}, [r3], r1

        vld1.8          {d2}, [r0], r1   
        vaddw.u8        q2,  q0,  d2
        vqmovun.s16     d3,  q2      
        vst1.8          {d3}, [r3], r1

        vld1.8          {d2}, [r0], r1   
        vaddw.u8        q2,  q0,  d2
        vqmovun.s16     d3,  q2      
        vst1.8          {d3}, [r3], r1

        vld1.8          {d2}, [r0], r1   
        vaddw.u8        q2,  q0,  d2
        vqmovun.s16     d3,  q2      
        vst1.8          {d3}, [r3], r1

        vld1.8          {d2}, [r0], r1   
        vaddw.u8        q2,  q0,  d2
        vqmovun.s16     d3,  q2      
        vst1.8          {d3}, [r3], r1

        mov             pc, lr               
.end
