#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�����岿��");
	set_long( 
@LONG_DESCRIPTION
�����ǰ����岿��Ⱥ�����߿���ͨ�����ڣ����߿�ͨ���㳡������Ľ������
��ʯ��ģ�������ס��������úܶ�ʯ���̳ɵ�·�ᴩ�������䣬����������˵�
�о��Ƿǳ������Ұ���ģ���ע�⵽�Ա���һ��������ͷ�����ӣ����紵��ʱ����ͷ
�¸����죬����ë���Ȼ��
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "west" : OGROUP"warea1",
     "southeast" : OGROUP"warea4",
     "northeast" : OGROUP"warea6" ]) );
set( "search_desc",([
     "here":"@@to_search_here",
     ]) );
set_outside("eastland");
reset();
}

string to_search_here()
{
  return  "\n�����·�Ե�һ��ʯ����������������\���С��������ÿ��С������һ�����Ӵ�����\n�����ӵ���һ�ˣ�������һ����\��ͷ��\n\n";
}
