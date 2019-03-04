#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("���вݵ�");
	set_long( @C_LONG_DESCRIPTION
���ߵ���һƬ�ݵ��ϣ����ܶ������֣�����ɽ�紵�ӡ����������⣬û
��һ�㳾�������������ľ���ɭ����Ϣ���������ÿһ������������������
�����ʱ�������׵�һ������ǣ���ſ��������������ѵõ���Ȼ֮����
������ϸһ����������һ���Ƥ(grass) ��ɫ�ƺ��������ݵز�ͬ������һ
�ֵ���ɫ���Ե�ʮ����Ŀ��
C_LONG_DESCRIPTION
	);
    set("item_desc", ([ "grass" : @C_LONG
������ǰȥ��ϸ�۲��ǿ��Ƥ��������������\��ʮ�ֿɰ�������ɫС��׺
�ɵģ���! ���һ����Ҷ��ͨ��ϸ�̣����������������õ�ҩ�ݣ�����\��
�����ڼ����ȥ����������� !
C_LONG
	]));
    set("objects", ([
        "snakea" : "/d/noden/monster/snake",
        "snakeb" : "/d/noden/monster/snake",
    ]) );
    set("herb_left", 2);
        set_outside("eastland");
	set( "exits", ([
         "east" : SAULIN"entrance",
	]) );
	reset();
}

void init()
{
    add_action( "dig_herb", "dig" );
}

int dig_herb(string arg)
{
    if( !arg || arg !="herb" )
		return notify_fail( can_read_chinese() ?
		  "�㶫�����ڵ��۵�����󺹲����������㲻֪��Ҫ��ʲ�᣿\n" :
		  "Dig what ?\n" );
	else if( query("herb_left") < 1 ) {
		tell_object(this_player(), can_read_chinese() ?
			"��֪���Ǹ�ȱ�¹������Ƥ�ϵ�ֲ�ﶼ���ڵ��ˡ�\n":
			"There are no herbs here.\n"
		);
		return 1;
	} else {
	if (present("snake",environment(this_player())))
	{
        tell_object(this_player(), 
	"�������� !! ��Щҩ��������һ���ߣ�����Ҫ�Ȱ������߰� !!\n" 
	);
	return 1;
	}
        tell_object(this_player(), @GOT_HERB
�������ϸ�ĵ�������ҩ���ڳ���������������ϣ�ҩ�ݸ��Ե���䣬����
������㲻��������(pack)�ٸϿ��ֻ����ﲢ�ҽ���һ��ư��ˮ����������
�������ʧ�ĺܿ졣
GOT_HERB
		);
		add("herb_left", -1);
		new( SAULIN_OBJ"herb" )->move(this_player());
		return 1;
	}
}

void reset()
{
	set("herb_left", 2);
	::reset();
}
