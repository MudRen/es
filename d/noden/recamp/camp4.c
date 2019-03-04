// Generated by Roommaker Tue Dec  7 22:16:00 1993
// Modified by freeway 5/15 1995

#include <mudlib.h>
#include "camp.h" 

inherit ROOM;

void create()
{
	::create();
   set_short("����");
	set_long( @LONG_DESCRIPTION
����������һ���Ƚϴ���������İ���������һ�ָо���ס�����
�����������һ����һλ���͵�սʿ���㿴����������һ����Ƥ����Χ��һ
��ѵ�Ұ��ͷ�ǣ�����ս��Ʒ��ı�����ѷ���������ǰ��һ�����Σ�����
����һ����ʰ�쵵Ļ�Ƥ������ǰ����һ������(cauldron)������¯������
����ɢ����һ����ζ�������ﻹ����һ�����˵�����ͼƬ(picture)��
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
		"cauldron" : @LONG_TEXT
������ӵ���ζʹ���̲�ס�쳤��������ͷ������....��....һ��������
��ͷ­���ڹ����������۵�С�ۣ���ͻȻ���������ζ����е���ˡ�
LONG_TEXT
,
                "picture":@C_LONG
�㲻�������̿�ˮ��������Ȼ���٣��������������������л���������
�������Ů�������Ը������˵����ƣ��󵨵�չ¶���ǽ��������ġ���
��������������������ĺۼ����㲻��Ҳ��Ҫ������(touch)��
C_LONG
		]) );

	set( "exits", ([ 
		"south" : "/d/noden/recamp/camp1" ]) );
	set( "objects", ([ 
		"leader" : "/d/noden/recamp/npc/leader" ]) );
		
	reset();
}

void init()
{
	add_action("do_touch","touch");
}

int do_touch(string arg)
{
	if ( !arg || arg != "picture" )
		return notify_fail("��Ҫ��ʲ�᣿\n");
	if ( !query("exits/down") ) {
	write(@LONG
��¶��а���Ц�ݣ�������ͼ������Ĳ�����ȥ�����������ģ��������һ����
�����˫�������ʹ��һ�С�˫�����项��ͻȻ���ġ���һ�����±߳�����һ��
���š�
LONG
	);
	tell_room(this_object(),this_player()->query("c_name")+
	"������ͼ������Ĳ�����ȥ��ͻȻ���ġ���һ�����±߳�����һ�����š�\n",
	this_player() );
	set("exits/down",CAMP"camp5");
   set( "exit_suppress", ({ "down" }) );
	return 1;
	}
	write("��������ͼ������Ĳ�����ȥ�����ž��Զ�����������\n");
	delete("exits/down");
	return 1;
}

void reset()
{
	delete("exits/down");
	::reset();
}