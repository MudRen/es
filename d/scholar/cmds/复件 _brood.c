//#pragma save_binary
// _brood.c
// This command is for spell users to quiet down and concentrate on recover
// spell points.
// by Annihilator@Eastern.Stories (12-17-93)
// modified by Oldcat@Eastern.Stories (1-18-95)
#include <mudlib.h>

inherit DAEMON;
string *c_illusion = ({
        "�񽫰��Էְ˽ڣ�һ��ͳ��Ϊ���ڡ�\n",
        "�������ݷ�˳�棬һ����Ԫ��Ī�⡣\n",
        "���ն�����һԪ����������Ϊ׼�ġ�\n",
        "��ȡ�Ź�Ϊ���ǣ�������������С�\n",
        "�Ź����Ϊֱ��������ֱʹ�Է�����\n",
        "����֮��Ϊֱʹ��ʮʱһλ��ƾ�ݡ�\n",
        "ֱ����ǲ��ʱ�ɣ�ֱʹ��˳�ݹ�ȥ��\n",
        "����Ԫ�������������漴���ұ�����\n",
        "����˳�����沼������������˳�С�\n",
        "����ż�������棬ֱ�����ư����ˡ�\n",
        "���ϴӰ��Ӽ�㣬�Ź�������΢�á�\n",
        "�����ʹ�Ͽ�ȡ��������֮��С����\n",
        "�ҷ�Ȯ�����������Ů��������\n",
        "�������������ǣ���Ϊ��Ů�����顣\n",
        "������˽�ͺ��£������������ơ�\n",
        "���������ĵػ����ʾ��˷���δ���\n",
        "̫��С����ӿ�����������˽��·��\n",
	"�ػ���Σ���뿪�����½ԴӴ���ȥ��\n",
        "����̫��̫����������Ԫ�ǵ�˽�š�\n",
        "������������ҫ�����Ű�����������\n",
        "̫��������Ϊ����Ȼ��׼�˻رܡ�\n",
        "������ȡ�����У������ɽ����η��\n",
        "��Ϊ������Ϊ����ʤ�����������塣\n"
});

void do_brood( object player, int skill, int degree )
{
	int mana, max;

	if( degree < 10  && (int)player->query("hit_points") > 20 &&
		skill > random(degree*degree*2) ) {
		message( "illusion", 
                        "��Ĭ��...."+c_illusion[random(23)],player );
		mana = (int)player->query("spell_points");
		max = (int)player->query("max_sp");
		player->add("hit_points",-3);
		if( mana + degree * 3 > max )
			player->set("spell_points", max );
		else
			player->set("spell_points", mana + degree * 3 );
		call_out( "do_brood", 3, player, skill, degree + 1 );
	} else {
	    player->delete_temp("meditating");
		player->delete_temp("block_defense");
		player->delete_temp("block_command");
//		player->delete_temp("block_message");
		tell_object( player,"ͻȻ���������һƬ�հ�....��\n");
		tell_object( player,"Ȼ����Χ������������������ö����壬��Ӵ��������˹�����\n");
		tell_room( environment(player), 
			player->query("c_name")+ "�����۾������˿����ܣ�վ��������\n",
			player );
	    call_out( "quit_brood", degree*12, player );
	    player->set("next_brood", (int)player->query("age") + degree*12 );
	}
}

void quit_brood( object player )
{
    tell_object( player,set_color("����þ������ܼ����ˡ�\n","HIY") );
}

int cmd_brood()
{
	int brood_skill, hp;

	brood_skill = (int)this_player()->query_skill("brood");
	if( !brood_skill ) return notify_fail( 
		"��û��ѧ�������ķ��������ܻ��ڴ�����������ʧ....��\n");
	hp = (int)this_player()->query("hit_points");
	if( hp <21 ) return notify_fail( 
		"���������˹�����أ��޷�����....��\n");
        if( this_player()->query_temp("exercising") ) return notify_fail("�����ھ۵����޷�����...��\n");
	// Modified by Annihilator - to prevent quit-and-meditate bug
    if( (int)this_player()->query( "next_brood" ) >
        (int)this_player()->query( "age" ) )
      return notify_fail("����Ҫһ��ʱ����Ϣ�������ټ��о������....��\n");
	write("��ϯ���������������о��񣬿�ʼ����....��\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+ "ϯ�ض����������۾�����ʼ����....��\n",
		this_player() );
	this_player()->set_temp("meditating", 1);
    if( !wizardp( this_player() ) ) {
 		this_player()->set_temp("block_defense", 1 );
 		this_player()->set_temp("block_command", 1 );
// 		this_player()->set_temp("block_message", 1 );
	}
	call_out( "do_brood", 3, this_player(), brood_skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
ָ���ʽ�� brood

���ָ��ʹ�����¿�ʼ���������������ʱ����ľ�����(sp)��ָ��ı�ƽ���죬
�����ʱ��ĳ�����������ļ��ܸߵ����жϣ�����Ӵ��������������һ��ʱ��
û�а취�ٴ�����
HELP
	);
    return 1;
}
