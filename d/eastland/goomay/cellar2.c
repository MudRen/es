
#include <goomay.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("�ض�");
	set_long( @LONG_DESCRIPTION
��������λ�һ��������ͨ���У�����ͨ����������\��ú����̿�ң�
ͨ����������ɵ��ŷ���һ�����Ļ�¯������������ԭ��������һ��������
���ӵ������Ĵ��Ҷ��Ĺ��߿�����ԭ���������ƺ��ߵĺܴ�æ��������Ҳ��
��������������û���κε�͸���ף����ǲ�֪�������������ȷ�һ����ش�
������о���������....
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : Goomay"cellar1" ,
                "south" : Goomay"cellar3" ,
                "east" : Goomay"cellar4" ,

	]) );

	create_door( "north", "south", ([
                "keyword" : ({ "steel door", "door" }),
                "name" : "steel door",
                "c_name" : "����",
                "c_desc" : @C_DESC
����һ���ɾ������ɵ��ţ����ؽ�ʵ��������Ȼ�����˻ҳ���˿��
���ǵ��꾫���Ĵ�����Ȼ��΢���Ļ���¾�ǿ�ط��������ĻԹ⡣
C_DESC
,		"status" : "locked",
                "lock" : "FIRE_ELEMENT_KEY"
        ]) );

	reset();
}

