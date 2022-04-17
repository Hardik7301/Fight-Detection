#ifndef __FRAME_H
#define __FRAME_H

#include "mem_pool.hpp"

struct Frame {
  int seq_len;
  int msg_len;
  int det_len;
  unsigned char *seq_buf;
  unsigned char *msg_buf;
  unsigned char *det_buf;
};

// change const value accordingly
const int SEQ_BUF_LEN = 100;
const int MSG_BUF_LEN = 76800;
const int DET_BUF_LEN = 25600;	
const int JSON_BUF_LEN = MSG_BUF_LEN * 2;
class Frame_pool
{
private:
  CMemPool *mem_pool_msg;
  CMemPool *mem_pool_seq;
  CMemPool *mem_pool_det;
  const int MEM_POOL_UNIT_NUM = 5000;

public:
  Frame_pool();
  Frame_pool(int unit_num);
  Frame alloc_frame(void);
  void free_frame(Frame& frame);
  void frame_init(Frame& frame);
  ~Frame_pool();
};

int frame_to_json(void* buf, const Frame& frame);
void json_to_frame(void* buf, Frame& frame);

#endif
