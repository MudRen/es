#include "saulin_temple.h"

inherit ROOM;

void create()
{
	object well;
	::create();
	set_short( "ҩ��");
	set_long( @C_LONG_DESCRIPTION
������һƬ������ҩ�ԣ�����һ��������������\������ֵֹ�ֲ����
�������Ҳû�����ģ���֪�����Ĵ�ʦ�Ǵ������ռ���������ҩ�ݣ�ҩ�ԵĶ�
�߻���һ��յأ���������(plant) �µ�ҩ�ݵģ������ǻ���һ����(well)����
ҩ�ԵĹ��ˮԴ��
C_LONG_DESCRIPTION
	);
    well = new(SAULIN_OBJ"dry_well");
    well->move(this_object());
    set_outside("eastland");
	set( "exits", ([ "west" : SAULIN"herb_room", ]) );
	reset();	
}

void init()
{
    add_action("climb_well", "climb");
}

int climb_well(string arg)
{
	if( !arg || arg!="well" )
      return notify_fail("��ʲ�᣿\n");
    tell_object( this_player(), 
      "��С�ĵ�������Ե���¾��ף�ͻȻ������һ���ȿ�....\n" 
    );
    tell_room( this_object(), 
      this_player()->query("c_cap_name")+
      "�������뾮��...��ѽ! ��ͷ�½��ϵ��Խ�ȥ�ˣ�����ʵ���� ...\n"
      ,this_player()
    );
    this_player()->move_player( SAULIN"under_well1", "SNEAK" );
    tell_room( environment(this_player()), 
      this_player()->query("c_cap_name") + "�Ӿ���ֱֱ������������\n"
      ,this_player()
    );
    return 1;
}
