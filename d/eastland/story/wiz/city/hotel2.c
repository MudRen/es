#include "../../story.h"

inherit ROOM;

void create()
{
	::create();
        set_short("�ùݶ�¥");
	set("long",@LONG
�������ùݶ�¥����ɨ�ú�Ǭ���������൱���������˰���һ���ŵĴ����⣬
ÿ�����Աߵ������ϻ���Щ��ˮ����������˶����ڴ��ϱ�Ŀ��������ҵ����Ϣ
��Ͼ�����׼�����������Ҫ��¥��˭Ҳ��ȥ����˭��
LONG
	);
	set("light", 1);
        set("exits",([
           "down" : SCITY"hotel1"
        ]) );
	reset();
}
