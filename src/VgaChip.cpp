/*

    Silice FPGA language and compiler
    (c) Sylvain Lefebvre - @sylefeb

This work and all associated files are under the

     GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
        
A copy of the license full text is included in 
the distribution, please refer to it for details.

(header_1_0)
*/
// Sylvain Lefebvre 2019-09-26

#include "VgaChip.h"
#include "video_out.h"

VgaChip::VgaChip()
{
  m_W = VGA_W;
  m_H = VGA_H;
  m_VideoOut = new VideoOut(
        0/*debug*/,2/*color depth*/,0/*polarity*/,
        m_W,VGA_W_FPORCH,VGA_W_PULSE,VGA_W_BPORCH,
        m_H,VGA_H_FPORCH,VGA_H_PULSE,VGA_H_BPORCH,
        "vgaout");
}

VgaChip::~VgaChip()
{
  delete (m_VideoOut);
}

void VgaChip::step(
            uint8_t  clk,
            uint8_t  vs,
            uint8_t  hs,
            uint8_t  red,
            uint8_t  green,
            uint8_t  blue)
{
  m_VideoOut->eval_RGB_HV(clk,vs,hs,red,green,blue);
}

LibSL::Image::ImageRGBA_Ptr VgaChip::frameBuffer() 
{ 
  return m_VideoOut->frameBuffer(); 
}

bool VgaChip::frameBufferChanged() const
{
  return m_VideoOut->frameBufferChanged();
}

