////#pragma save_binary
#include <mudlib.h>
#define in_msg ({ "���ҵ�һ�������Ľ������������\n","��㵽���ӵ����档\n",\
		"�㿪ʼαװ��һ������\n","�㿪ʼ�� : �㿴������ ... �㿴������ ...\n",\
		"����Լ����۾���������\n","������ǽ���ϣ��૵��� : ���Ǳڻ� ... ���Ǳڻ� ...\n",\
		"�㱣�ְ�ף���װ��һ�����ӡ�\n","��ſ�ڵ���, ��Ҳ������\n" })
#define out_msg ({ "�����һ֧��֦����װ��һ������\n","����ͷ�ϲ�����ݣ���װ�ǲݴԡ�\n",\
		"����ڵ��ϣ�αװ��һ�Ŵ�ʯͷ��\n","����\����\�ŵĶ㵽�ݴ��\n",\
		"���ҵ�һ�������Ľ������������\n","�㿪ʼ�� : �㿴������ ... �㿴������ ...\n",\
		})

inherit DAEMON;

int hide_idle(object me,int succeed)
{
	me->add_temp("hide_score",succeed);
	if ( environment(me)->query("outside") ) 
                me->quick_message(out_msg[random(6)]);
	else
                me->quick_message(in_msg[random(8)]);
	return 1;
}

int check_hide(object me)
{
	int skill;
	object ob,attacker;

	if ( attacker = me->query_attacker()  ) {
		if ( !ob = attacker->query_attacker()) return 0;
		if ( (string)ob->query("name") == (string) me->query("name") )
			return -100;
	}
// ֻ�� skill �й� ....
	skill = (int) me->query_skill("hide");
	if ( skill )
		skill += (int) me->query("thief_level/backstab")/2 + 10;
	else
		return 0;
	return (random(skill));
}

int cmd_hide()
{
	int score;
	if ( (int)this_player()->query_temp("next_action") > time() )
		return notify_fail("���������������� ...\n");
	write(set_color("�㿪ʼ��취���ز� ...\n","HIY"));
	score = check_hide(this_player());
	if ( score < random(60) )
	tell_room(environment(this_player()),
			sprintf("%s��ʼ�������ز� ...\n",this_player()->query("c_name"))
			,this_player() );

	this_player()->set_temp("next_action",time()+2);
	this_player()->set_temp("hidding",1);
	call_out("hide_idle",2,this_player(),score);
	return 1;
}

int help()
{
	write (@HELP
Usage: hide

���ָ����ʹ�����ø��ֵ��ε����������Լ���ʹ�����ܵ��˲��ٶ���
�����н��ģ�����ɹ�\�Ļ����㽫��ʱ��������ǰ��ʧ��ֱ�����ٴ���
�����ǵĺ����ġ�����㲻�¸�������Ц�㣬���Լ����Ǻ��п��ܳɹ�
�ģ�����ҪС�ı���������Ϊǿ��

HELP
);
	return 1;
}
