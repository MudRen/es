
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The Factory of Drawf mine","����");
    set_long(@Long
Long
,@CLong
һ��һ�ѵĿ�ʯ�ѻ��ڴ�,��һЩ�о���İ��˿����ڰѿ�ʯ����,Ȼ����
�����ʹ�.���ʹ���ĩ����һ���޴�Ļ�¯, ���ܵĻ���������Ϣ��ȼ����.����
��һ������ .�㿴����Щ�ǳ��������豸���������԰��˵���������������
Щ���ߵ� .��һЩ�˿����ڰѿ�ʯж��,��һЩ�յ��˿�����������ȥ�˿�.
ÿ�����˶��ǳ����ڵĹ���.���ڵ���������������.ר���˿�ͨ��ʹ��.
CLong
);
set("open_cart",1);
set("exits",([
            "west":Deathland"/mine/mine_01",
             ]));

set("objects",([
    "homdlaser":Monster"/homdlaser",
   ]));
set("direction","west");
::reset();
}

int clean_up() { return 0; } 
