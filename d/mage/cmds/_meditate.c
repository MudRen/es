//#pragma save_binary
// _meditate.c
// This command is for spell users to quiet down and concentrate on recover
// spell points.
// by Annihilator@Eastern.Stories (12-17-93)
#include <mudlib.h>

inherit DAEMON;
string *c_illusion = ({
	"һ�����ʵĹ�����������һ�������������壬��ת��....��\n",
	"���ɴ��󽻲�Ļ�����������л���׷������������Ļ��������ȼ��\n"
	"��....��\n",
	"����ɫ���Ʋ��У�������������͸��ˮ������������Զ���������������....��\n",
	"һȺ������ɫ���ӵľ��ˣ�������Ϣ�ش���ɽ�е�һ��Ͽ�ȣ�����������\n"
	"�����ʬ����ݻƵ�ֲ��....��\n",
	"ˮ����һ���޴�ĺ�Ӱ���ݵ��ζ���������ӳ��ˮ���һֻ�����Ӱ�ӣ�\n"
	"��������׷����ˮ�е���Ȼ����....��\n",
	"������ò��ȫһ���Ŀ������������������������и�����һ�����������\n"
	"ˮƿ��ˮ������������һƬ����������....��\n",
	"��һƬ�ں������ཬ������һ��������ĭ��ÿ����ĭһ���ѣ�����һ��\n"
	"�����ɲ������ɳ���....��\n",
	"ɭ����������ɫ�ĺ����ڷ�������Ȼ��һֻȼ�����ܻ���Ķ����޳����\n"
	"��Ⱥ��....��\n",
	"�����������µ���ʿ��һƬ������ʬ�ĸߵ��Ͼ�����һ��������ߵ���Ů��\n"
	"һ����Ĭ�ؿ��� ....��\n",
	"��ǧ�����ʿ����������ؿ�����ɱѽ��ɱѽ������һ����ʿ����Χ����\n"
	"�������������ò�м�������������Щ����ʿ����\n",
	"һֻ�޴����ɫ����������ͷ��������һ�������������괵�����ĳ��ѡ�\n",
	"��ҹ�������ɫ����Ӱ������Ϣ����һ�������������ϵĳǱ�Ʈȥ�����\n"
	"����Ʈ��ϸ�� .....��\n"
});

void do_meditate( object player, int skill, int degree )
{
	int mana, max;

        if (!player) return;
	if( degree < 10  && (int)player->query("hit_points") > 20 &&
		skill > random(degree*degree*2) ) {
		message( "illusion", 
                        "�㿴��...."+c_illusion[random(12)],player );
		mana = (int)player->query("spell_points");
		max = (int)player->query("max_sp");
		player->add("hit_points",-3);
		if( mana + degree * 3 > max )
			player->set("spell_points", max );
		else
			player->set("spell_points", mana + degree * 3 );
		call_out( "do_meditate", 3, player, skill, degree + 1 );
	} else {
	    player->delete_temp("meditating");
		player->delete_temp("block_defense");
		player->delete_temp("block_command");
//		player->delete_temp("block_message");
		tell_object( player,"һƬ��ڣ�ʲ��Ҳû�еĿռ�....��\n");
		tell_object( player,"Ȼ����Χ������������������ö����壬���ڤ˼�����˹�����\n");
    if( !(player->query("player_invisible") )) {
		tell_room( environment(player), 
                        sprintf("%s�����۾������˿����ܣ�վ��������\n",player->query("c_name")),
			player );}
	    call_out( "quit_meditate", degree*12, player );
	    player->set("next_meditate", (int)player->query("age") + degree*12 );
	}
}

void quit_meditate( object player )
{
	if ( !nullp(player) )
    tell_object( player,set_color("����þ������ܼ����ˡ�\n","HIY" ));
}

int cmd_meditate()
{
	int med_skill, hp;

	med_skill = (int)this_player()->query_skill("meditate");
	if( !med_skill ) return notify_fail( 
		"��û��ѧ��ڤ˼�ķ��������ܻ���ڤ˼��������ʧ....��\n");
	hp = (int)this_player()->query("hit_points");
	if( hp <21 ) return notify_fail( 
		"���������˹�����أ��޷�ڤ˼....��\n");
	// Modified by Annihilator - to prevent quit-and-meditate bug
    if( (int)this_player()->query( "next_meditate" ) >
        (int)this_player()->query( "age" ) )
      return notify_fail("����Ҫһ��ʱ����Ϣ�������ټ��о���ڤ˼....��\n");
	write("��ϯ���������������о��񣬿�ʼڤ˼....��\n");
	    if( !(this_player()->query("player_invisible") )){
	tell_room( environment(this_player()), 
                sprintf("%sϯ�ض����������۾�����ʼڤ˼....��\n",this_player()->query("c_name")),
		this_player() );}
	this_player()->set_temp("meditating", 1);
    if( !wizardp( this_player() ) ) {
 		this_player()->set_temp("block_defense", 1 );
 		this_player()->set_temp("block_command", 1 );
// 		this_player()->set_temp("block_message", 1 );
	}
	call_out( "do_meditate", 3, this_player(), med_skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
Syntax: meditate

This command is to sit down and meditate. When you are meditating, spell
points recovery is much faster than usual. How long you can meditate depends
on your meditate skill. Once you are awake from meditating, you'll have have
some headache. But that's normal.
HELP
	);
    return 1;
}