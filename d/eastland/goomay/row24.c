// File: /d/eastland/goomay/mroad1.c
// create by : Ruby the little wizard from 5/6/1994

#include <goomay.h>
inherit ROOM;
string *c_msg = ({
"ǽ��Ϳ�������߰�����֣�������ֲ����������дЩʲ�ᡣ\n",
"ǽ�ڵ����½ǻ���һ��С��ɡ��ɡ��д��������������..\n",
"ǽ�ڵ������汻����ָ������������è�����δ�ʤ���깷���\n",
});

void create()
{
	::create();
	set_short("��ʯ����");
	set_long( @LONG_DESCRIPTION
�����ڹ�÷��ƽ̹����ʯ����ϣ�������ʯ����ʾ���������Ļ�����
����������ߵ���С����ߺ������������������ż�����۶����Ŀ�����
��һЩ��Ҫ���������������÷������糾ɳ�У���֪�����˶��������˵�
���롣�ֵ����������ȥ������������������䶷��᳡�����ſ�ȴ������
����Ƕ¸�ǽ�ϱ�Ϳ�������߰�����֡�
LONG_DESCRIPTION
	);
        set("c_item_desc",(["wall":"@@look_wall"
                  ]));

        set_outside( "eastland" );
	set( "exits", ([ 
                "east" : Goomay"col24",
		"west" : Goomay"row25",
	]) );
        set( "objects", ([
                "woman1" : Mob"visitor",
                "woman2" : Mob"visitor",
        ]) );

	reset();
}

string look_wall()
{
	return c_msg[random(sizeof(c_msg))];
}
