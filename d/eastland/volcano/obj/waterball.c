#include "../oldcat.h"

inherit OBJECT;

void init()
{
	add_action( "hold_ball", "hold" );
}

void create()
{
        set_name( "prevent_water ball", "��ˮ��" );
        add( "id", ({ "ball" }) );
        set_short( "��ˮ��" );
        set_long(
@LONG
һ���ö����޵Ľ�ĥ�Ƶı�ˮ�飬��˵ֻҪ�����������Ϳɽ�ˮ�ֳ�һ��·����
LONG
		);
   		set("unit","��");
   		set("weight", 10);
   		set("value",({10, "silver"}) );
                set("no_sale", 1 );
}

int hold_ball(string arg)
{
    if( !arg || arg != "ball" ) return 0;
    if ((int)environment(this_player())->query("in_well")==1 ) {
    	tell_object(this_player(),
    	    "�����ձ�ˮ�飬ֻ����ǰ��ˮ�Զ��ֳ�һ��·����\n");
        this_player()->set_temp("likefish",1);
    } else
        tell_object(this_player(), 
             "�����ձ�ˮ�飬�����ǲ����ô�ط����ء�\n" );
    return 1;

}
