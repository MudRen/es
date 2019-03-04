#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 0) ;
        set_short( "����" );
        set_long(
@LONG
������һ�ھ����峺�ľ�ˮ�ھ��е�����������\��ƶ������Ů���ھ���
ϴ�·����죬��������һƬ��������
LONG
        );
        
        set( "exits", ([
		"west"  : Goomay"ruin2",
        ]) );
        set( "objects", ([
                "woman" : Mob"poor_woman",
                "woman2" : Mob"poor_woman",
                "woman3" : Mob"poor_woman",
                "cat"   : "/d/noden/nodania/monster/cat",
		]));
        set("c_item_desc",(["well":@C_LONG
    ��̽ͷ������һ�ƣ�ֻ�����Ե�΢������ˮ��Ĳ���ҡҷ����
������ϸһ����ͻȻ������ߵľ�Ȧ������Щĥ�𣬾ͺ������˳���
����һ�㣬����\��Ҳ��������ȥ��
C_LONG
        ]));

        reset();
}
void init()
{
        add_action( "climb_well", "climb" );
}

int climb_well(string arg)
{

        if( !arg || arg!="well" )
        return notify_fail("���ڵ��ϵ���������\n");

	if ((int)this_player()->query_skill("climbing")<20)
	{
        tell_object(this_player(),
        "��С�ĵ���Ҫ������Ե���¾��ף�ͻȻ������һ���ȿգ�ˤ�˸��Ľų��� !!\n");

        tell_room( this_object(), 
        this_player()->query("c_name") + "�������뾮��...��ѽ ! ��ˤ�˸��Ľų��죬����ʵ���� ...\n",
                this_player() );
	return 1;
	}

        tell_object(this_player(),
	"��С�ĵ�������Ե���¾��ף�ͻȻ������һ���ȿ�....\n");

        tell_room( this_object(), 
	this_player()->query("c_name") + "�������뾮��...��ѽ ! ��ͷ�½��ϵ��Խ�ȥ�ˣ�����ʵ���� ...\n",
                this_player() );
        this_player()->move_player( Goomay"under_well", "SNEAK" );
        tell_room( Goomay"under_well", 
		this_player()->query("c_name") + "�Ӿ���ֱֱ������������\n"
		,this_player() );
        return 1;
}
