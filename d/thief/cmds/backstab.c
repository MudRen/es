//#pragma save_binary
#include <mudlib.h>
//	#define RATE ({ 5,20,32,41,47,50,53,59,68,80,95, })
// 	#define RATE ({ 7,25,40,52,61,67,70,73,79,88,95 })
//	#define RATE ({ 3,16,27,39,50,60,67,75,82,90,95 })
#define 	RATE ({ 3,15,27,41,53,65,70,75,82,90,95 })
inherit DAEMON;

void remove_block(object me)
{
	me->delete_temp("block_command");
	return;
}

void make_hurt(object me,object target,object weapon)
{
	int dam,time,dam_align,victim_db ;
	string msg;
	target->set("last_attacker",me);
	time = target->query_temp("bs");
	victim_db = target->query("defense_bonus");
	dam = (int)me->query("max_damage1")+(int)me->query("min_damage1");
	dam = dam * (int)me->query_skill("dagger")/100 ;
	dam = dam + random( dam ) ;
	//dam = ( dam * 6 ) /( 4 + time ) ;
	dam = ( dam * 8 ) /( 5 + time ) ;
	dam_align = -(int)me->query("alignment")/2000 ;

	dam = (dam < 5 ? 5 : dam ) + random( (int)me->query_level() ) + 
			( dam_align > 20 ? 20 : dam_align )-victim_db;

//	write( sprintf("[ info ] damage : %d\n",dam) );
	target->receive_damage(dam);
	me->gain_experience(dam+dam);
	target->add_temp("bs",1);
	msg = "/adm/daemons/statsd"->status_string(target) ;
    tell_object( target,sprintf("( ��%s )\n",msg));
    printf("( %s%s )\n",target->query("c_name"),msg);
	return;
}

int backstab_idle(object me,object target,int succeed)
{
	object weapon;

	me->set_temp("backstabed",0);

	if ( !target || nullp(target) || target->query("hit_points") < 1) {
		write("�Ǽһ��Ѿ�����, �ͷŹ����ġ���� ��\n");
		return 1; 
	}
	if ( !present(target,environment(me))) {
		write("��ѽ !! Ŀ�������� ..\n");
		return 1;
	}
	weapon = me->query("weapon1");
	tell_object(me,set_color(
		sprintf("�û��� !! ���ս�%s��%s�ı��������� !!\n",
			weapon->query("c_name"),target->query("c_name")),"HIY"));
			
	tell_room(environment(me),set_color(
		sprintf("%s����ӰͻȻ��%s���ḡ�ֳ���������ɱ������ ...\n",
				me->query("c_name"),target->query("c_name")),"HIR"),
			({me,target}));


	if ( ! weapon ) succeed = 0;
	else if ( (string)weapon->query("type") != "dagger" )
		succeed = 0;

	me->kill_ob(target);
	target->kill_ob(me);
	if ( !succeed ) {
	tell_room(environment(me),
		sprintf("%s��������%s����%s�ı���Ȼ���䣬��ѽ !! ��Ȼʧ���� ...\n",
		me->query("c_name"),weapon->query("c_name"),target->query("c_name")),
		({ me,target}) );
		tell_object(me,set_color(
			sprintf("%sͻȻת��ͷ�����������һЦ����ѽ !! ���� ...\n",
				target->query("c_name")),"HIR"));
		tell_object(target,set_color(
		sprintf("��ͻȻ�е�������ԣ��Ͽ�����һ����һ����׵Ļ��⿰������\n"
					"��ı�����е�һ��ë���Ȼ���ɶ� !! ��%s�ı��� ...\n",
				me->query("c_name")),"HIM"));
        me->block_attack(4);
        me->set_temp("block_command",1);
        me->set_temp("msg_stop_attack",
                "( ��ոձ���ʧ�֣���æ���ң�û�취�������� ! )\n" );
		call_out("remove_block",3,me);
		return 1;
	}	
	else {
	tell_room(environment(me),
		sprintf("%s��������%s����%s�ı���Ȼ���䣬��ʱѪ���Ľ� ...\n",
		me->query("c_name"),weapon->query("c_name"),target->query("c_name")),
		({ me,target}) );
		tell_object(me,set_color(
			sprintf("%sһ��˻��������Ѫ�������%s���˳������ɹ�\�� !!\n"
					"һ��а��Ŀ��������������� !! \n",
				target->query("c_name"),weapon->query("c_name")),"HIY"));
		tell_object(target,set_color(
		sprintf("��ͻȻ�е�һ���ʹ��һ��ѩ�׵ĵ��д�����ؿ�ð�˳�����\n"
				"�㲻֪����Ŀ�����������һ����ѣ���ɶ� !! ��%s�ı��� ...\n",
				me->query("c_name")),"HIR"));
		make_hurt(me,target,weapon);
		return 1;
	}
	return 1;
}

int check_backstab(object me,object target)
{
	int iq,dex,kar,rate,level,skill,lv;

	lv = target->query_level();
//	write("[ info ] hide_score : " + me->query_temp("hide_score") + "\n");
	if ( !me->query_temp("hidding") ||
		(int)me->query_temp("hide_score") < lv*lv) 
		return 0;
	skill = (int) me->query_skill("backstab");
	if ( ! skill ) return 0;
//	level = skill/5 - (int)target->query_level() + 6;
	level = skill/5 - (int)target->query_level() + 4;

	iq = (int)me->query_stat("int")-(int)target->query_stat("int");
	dex = (int)me->query_stat("dex")-(int)target->query_stat("dex");
	kar = (int)me->query_stat("kar")-(int)target->query_stat("kar");
	level = ( level < 0 ? 0 : level );
	level = ( level > 10 ? 10 : level );
	rate = RATE[level] + kar +kar + dex + dex + iq +iq;

//	write( sprintf("[ info ] rate = %d/120\n",rate) );
	if ( random(120) < rate )
		return 1;
	else
		return 0;
}
int cmd_backstab(string arg)
{
	object target,weapon;
	
	if ( this_player()->query_temp("backstabed") )
		return notify_fail("( ����������ר�ĵȴ����̵�ʱ���� )\n");
	if ( this_player()->query_temp("sneaked") )
		return notify_fail("( ������ר��Ǳ��, �޷����̡�)\n");
	if ( ! arg ) return notify_fail("���뱳��˭��\n");
	if ( !target = present( arg,environment(this_player())))
		return notify_fail("����û�н�"+arg+"�����\n");
	if ( arg == (string)this_player()->query("name"))
		return notify_fail("�����Լ����㲻��ƴ suicide ��\n");
	if ( ! living(target) ) 
		return notify_fail("�������Ĵ���"
			+target->query("c_name")+"����ʲ����Ҳû������\n");
	if ( !visible(target,this_player()) || target->query("invisible_player") )
		return notify_fail("���뱳��˭��\n");
	if ( !this_player()->query_vision() )
		return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");
	if ( target->query("no_attack") )
		return notify_fail("��һ����ɱ��\n");
	if ( userp(target) ) {
		if ( (int)target->query_level()< 5 || 
			 (int)this_player()->query_level()<5 )
		return notify_fail("�㲻�� PK �� !!\n");
	}
	weapon = this_player()->query("weapon1");
	if ( !weapon )
		return notify_fail("��û���������޷����� !!\n");	
	if ( (string)weapon->query("type") != "dagger" )
		return notify_fail("������������֣��޷����� !!\n");
	if ( (int)this_player()->query("alignment")>0 )
		return notify_fail("һ�����˽�ս����ʵ���²������������ֿ��µ��¡�\n");
			
	write(set_color(sprintf("�㿪ʼ�ȴ�����%s��ʱ�� ...\n",target->query("c_name")),"HIY"));

        this_player()->block_attack(4);
        this_player()->set_temp("msg_stop_attack",
                "( ����������ר�ĵȴ����̵�ʱ�����޷��������£� )\n" );
        this_player()->set_temp("backstabed",1);
	call_out("backstab_idle",2+random(4),this_player(),target,
				check_backstab(this_player(),target));
	return 1;
}

int help()
{
	write (@HELP
Usage: backstab <target>

�����Ŀ�������ȫû�н��ĵ�һ˲�䣬������������ָ����"����"����
������µ�ͻϮ����ɼ�����˿ڣ���춱Ƚ����ĵ�����������һ��������
�����������ĵ������Ȳ�������ͼ����͵�Ҫ���������ƾͼ��ˡ�

HELP
);
	return 1;
}
