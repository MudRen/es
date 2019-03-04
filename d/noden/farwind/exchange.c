//#pragma save_binary

// A basic coin exchange which inherits the standard coin exchange object.
// Needs to call ::create() like the shop does.

#include "farwind.h"
#include <money.h>

inherit "/std/exchange";
inherit ROOM;

void create()
{
	room::create() ;
	set("light",1) ;
    set_short( "Ǯ�Ҷһ�����");
	set_long(@C_LONG
������λ�Զ����Զ��������Ǯ�Ҷһ����ġ� ����������԰����ϵ�
����Ǯ�һ��ɽ�ҡ����ҡ�ͭ�ҵȡ�ֻҪ�� convert [����] [��Ǯ��] to
[��Ǯ��] ����Ϳ��԰�ָ�������ļ�Ǯ�һ��ɵ�ֵ����Ǯ�ҡ�����㲻ָ
�� [����]���ͻ�����������еļ�Ǯ�һ�����Ǯ�ҡ�
���󷽵�ǽ���и�Ǯ�Ҷһ���(sign)��
C_LONG
                );
	set ("exits", ([ "down" : FARWIND"bank" ]) );
   set( "c_item_desc", ([
          "sign" : 
@LONG
    Ŀǰ��������ͨ��Ǯ��ֻ������:
----------------------------------------------------------
  һ. �׽��(platinum): һö�׽�ҿɶһ�ʮö���.
  ��. ���(gold): һö��ҿɶһ�ʮö����.
  ��. ����(silver): һö���ҿɶһ�ʮöͭ��.
  ��. ͭ��(copper).
----------------------------------------------------------
LONG
     ]) );
}
