#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "�����޹�" );
	set_long(
@LONG
�������������޹�����������ɢ������͵Ĺ�â��һ������������󴲣�
���ӿ���������ʲ�����Ϸ��ƶ��ɣ���һ���൱��������ǽ���Ϲ���һ
�������ǳ������µ�һ�����֣�����˫˫֮�֣������������ĵ�̺����
���л���\��һ�躱���ı����㣬��˵�Ǿջ���һ�֡�
LONG
	);
	set( "exits", ([
	     "south" : OTEMP"palace4",
	]) );
        set("objects",([
            "dragon_king":OMONSTER"dragon_king",
            ]) );
         set("light",1);
         reset(); 
}
