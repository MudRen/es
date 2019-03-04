//#pragma save_binary
// _meditate.c
// This command is for spell users to quiet down and concentrate on recover
// spell points.
// by Annihilator@Eastern.Stories (12-17-93)
#include <mudlib.h>

inherit DAEMON;
string *c_illusion = ({
	"һ�����ʵĹ���������һ�������������壬��ת��....��\n",
	"���ɴ��󽻲�Ļ�����������л���׷������������Ļ��������ȼ��\n"
	"��....��\n",
	"����ɫ���Ʋ��У���\����������͸��ˮ������������Զ���������������....��\n",
	"һȺ������ɫ���ӵľ��ˣ�������Ϣ�ش���ɽ�е�һ��Ͽ�ȣ�����������\n"
	"����ġ������\�Ƶ�ֲ��....��\n",
	"ˮ����һ���޴�ĺ�Ӱ���ݵ��ζ���������ӳ��ˮ���һֻ�����Ӱ�ӣ�\n"
	"��������׷����ˮ�е���Ȼ����....��\n",
	"������ò��ȫһ���Ŀ������������������������и�����һ�����������\n"
	"ˮƿ��ˮ������������һƬ����������....��\n",
	"��һƬ�ں�����ཬ������һ��������ĭ��ÿ����ĭһ���ѣ�����һ��\n"
	"�����ɲ������ɳ���....��\n",
	"ɭ������\����ɫ�ĺ����ڷ�������Ȼ��һֻȼ�����ܻ���Ķ����޳����\n"
	"��Ⱥ��....��\n",
	"���������µ���ʿ��һƬ���������ĸߵ��Ͼ�����һ��������ߵ���Ů��\n"
	"һ����Ĭ�ؿ��� ....��\n",
	"��ǧ�����ʿ���������ؿ�����ɱѽ��ɱѽ������һ����ʿ����Χ����\n"
	"�������������ò�м�������������Щ����ʿ����\n",
	"һֻ�޴����ɫ����������ͷ��������һ�������������괵�����ĳ��ѡ�\n",
	"��ҹ����\���ɫ����Ӱ������Ϣ����һ�������������ϵĳǱ�Ʈȥ�����\n"
	"����Ʈ��ϸ�� .....��\n"
});

void do_meditate( object player, int skill, int degree )
{
	int mana, max, g_lvl;

	tell_object( player, "�㿴��....");
	g_lvl = (int)player->query_guild_level();
	if( degree < 10  && (int)player->query("hit_points") > 20 &&
		(skill+g_lvl) > random(degree*degree*2) ) {
		message( "illusion", 
			c_illusion[random(sizeof(c_illusion))]
			, player
		);
		mana = (int)player->query("spell_points");
		max = (int)player->query("max_sp");
		player->receive_damage(3-(g_lvl/30));
		if( mana + degree * (3+g_lvl/30) > max )
			player->set("spell_points", max );
		else
			player->set("spell_points", mana + degree * (3+g_lvl/30) );
		call_out( "do_meditate", 3, player, skill, degree + 1 );
	} else {
	    player->set_temp("meditating", 0);
	    if( !wizardp( player ) ) {
	      player->set_temp("block_defense",0);
		  player->set_temp("block_command",0);
		  player->set_temp("block_message",0);
	    }
		tell_object( player, "һƬ��ڣ�ʲ��Ҳû�еĿռ�....��\n");
		tell_object( player, "Ȼ����Χ������������������ö����壬���ڤ˼�����˹�����\n");
		tell_room( environment(player), 
			player->query("c_name")+ "�����۾������˿����ܣ�վ��������\n",
			player );
		player->gain_guild_experience(1+skill/10);
	    call_out( "quit_meditate", degree*12, player );
	    player->set("next_meditate", (int)player->query("age") + degree*12 );
	}
}

void quit_meditate( object player )
{
    tell_object( player, "����þ������ܼ����ˡ�\n" );
}

int cmd_meditate()
{
	int med_skill, hp;

	med_skill = (int)this_player()->query_skill("meditate");
	if( !med_skill ) return notify_fail( "��û��ѧ��ڤ˼�ķ��������ܻ���ڤ˼��������ʧ....��\n");
	hp = (int)this_player()->query("hit_points");
	if( hp <21 ) return notify_fail( "���������˹�����أ��޷�ڤ˼....��\n" );
	// Modified by Annihilator - to prevent quit-and-meditate bug
    if( (int)this_player()->query( "next_meditate" ) >
        (int)this_player()->query( "age" ) )
      return notify_fail("����Ҫһ��ʱ����Ϣ�������ټ��о���ڤ˼....��\n" );
	write( "��ϯ���������������о��񣬿�ʼڤ˼....��\n");
	tell_room( environment(this_player()),
		this_player()->query("c_name")+ "ϯ�ض����������۾�����ʼڤ˼....��\n",
		this_player() );
	this_player()->set_temp("meditating", 1);
    if( !wizardp( this_player() ) ) {
      this_player()->set_temp("block_defense", 1 );
   	  this_player()->set_temp("block_command", 1 );
	  this_player()->set_temp("block_message", 1 );
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
