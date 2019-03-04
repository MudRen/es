#include "../../story.h"

inherit "/std/bank";
inherit "/std/exchange";
inherit ROOM;

void create()
{
	exchange::create();
	room::create();
	set_short("Ǯׯ");
	set_long( @LONG
�����Ƕ�������������Ǯׯ��������֮һ���Դ��ڱ�ɽ���ֽ��֮�ᣬһʱ��
����˶�����������������ǮҲ���������࣬�ټ��������д����ϰ�ߣ���������
����ҵҲ�͸����������ϡ������������ ��(deposit) ��(withdraw) �������
�������� 25 ö��ҿ�����ͷ (open account) ���Ϳ��Խ����Ǯ�ķ���Ǯׯ�
����������Ҳ�ṩ�һ������������(convert) ָ��һ����ϵ�Ǯ�ң�������ͨ
��Ǯ�����඼д��ǽ�ڵ�һ�Ų��� (sign) �ϡ�
LONG
	);
	set( "light", 1 );
	set( "exits", ([ 
           "north" : SCITY"nw1" ]) );
	reset();
}
void init()
{
	bank::init();
	exchange::init();
}
