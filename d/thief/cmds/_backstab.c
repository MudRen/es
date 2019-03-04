//#pragma save_binary
#include <mudlib.h>
#include "../thief.h"
#define	RATE ({ 3,11,23,37,49,55,58,63,73,84,87 })

inherit DAEMON;

int modify_hurt(int base,int level)
{
	switch( level ) {
	    case 0: // so that level 0 have some power;
		return base/MAX_SKILL_LEVEL;
	    default :
		return base*level/MAX_SKILL_LEVEL;
	}
}

void calc_exp(object me,int dam,int lv)
{
	if ( dam > 0)
	    me->add("thief_exp/backstab",(dam+(int)me->query("thief_level/backstab"))/3+lv);
	else 
	    me->add("thief_exp/backstab",1);
	return;
}

void remove_block(object me)
{
        if (!me) return;
	me->delete_temp("block_command");
	return;
}

int make_hurt(object me,object target,object weapon)
{
	int dam,time,dam_align,victim_db ;
	string msg;

	target->set("last_attacker",me);
	time = target->query_temp("bs");
	victim_db = (int) target->query("defense_bonus");
	dam = (int)me->query("max_damage1")+(int)me->query("min_damage1");
	dam = dam * (int)me->query_perm_skill("dagger")/100;
	dam += random( dam ) ;
	dam = ( dam * 8 )/( 5 + time ) ;
	dam_align = -(int)me->query("alignment")/2000 ;
	dam += ( dam_align > 30) ? 30 : dam_align ;
	dam = modify_hurt(dam,(int)me->query("thief_level/backstab"));
	dam += ((int)target->query("hit_points")/25 - random(victim_db)/2);
	dam = (dam < 5 ? 5 : dam ) + (int)me->query_level() ;
	if ( wizardp(me) )
		tell_room(environment(me),"�����˺� :"+dam+"\n");
	target->receive_damage(dam);
	if(!environment(target)->query("PK_ZONE"))  me->gain_experience(dam+dam);
	target->add_temp("bs",1);
	msg = "/adm/daemons/statsd"->status_string(target) ;
    	tell_object( target,sprintf("( ��%s )\n",msg));
    	tell_object( me,sprintf("( %s%s )\n",target->query("c_name"),msg));
	return dam;
}

int backstab_idle(object me,object target,int succeed)
{
	object weapon;
	int dam = 0,kar;

	if ( !target || nullp(target) || target->query("hit_points") < 1) {
		write("�Ǽһ��Ѿ�����, �ͷŹ����ġ���� ��\n");
		return 1; 
	}
	if ( !present(target,environment(me))) {
		write("��ѽ !! Ŀ�������� ..\n");
		return 1;
	}
	// don't move the check to cmd_backstab
	if ( target->query("no_attack") ) 
		return notify_fail("��һ����ɱ��\n");

	/* Need we check weapon again ????? */
	weapon = me->query("weapon1");
	if ( !weapon )
		return notify_fail("��û���������޷����� !!\n");	
	tell_object(me,set_color(
		sprintf("�û��� !! ���ս�%s��%s�ı��������� !!\n",
			weapon->query("c_name"),target->query("c_name")),"HIY"));
			
	tell_room(environment(me),set_color(
		sprintf("%s����ӰͻȻ��%s���ḡ�ֳ���������ɱ������ ...\n",
				me->query("c_name"),target->query("c_name")),"HIR"),
			({me,target}));

	if ( (string)weapon->query("type") != "dagger" )
		succeed = 0;

	if ( !succeed ) {
		kar = (int) me->query_stat("karma");
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
		me->kill_ob(target);
		target->kill_ob(me);

		if ( random(kar*3/2) < (int) target->query_stat("dex") ) {
        		me->set_temp("block_command",1);
				call_out("remove_block",5,me);
		}
        	me->block_attack(4);
		me->delete_temp("doing_backstab");
        	me->set_temp("msg_stop_attack",
                "( ��ոձ���ʧ�֣���æ���ң�û�취�������� ! )\n" );
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
		dam = make_hurt(me,target,weapon);
		me->kill_ob(target);
		me->delete_temp("doing_backstab");
		target->kill_ob(me);
	}
	me->add("alignment",-dam/2);
	if(!environment(target)->query("PK_ZONE")) calc_exp(me,dam,(int)target->query_level());
	return 1;
}

//
// �ɹ��ʾ���� skill,����, ���Ƿ� hide �ɹ�
// ������� mob ��ս���л� block_attack, �ɹ��ʻ�����
//
int check_backstab(object me,object target)
{
	int iq,dex,kar,rate,level,skill,lv,extra,sc;

	lv = target->query_level();
	if( !(int)me->query_temp("hidding") || (sc = (int)me->query_temp("hide_score")) < lv*lv) 
		return 0;
	extra = sc/400; // hide ��θ�һ�� bonus ��
	if ( (int) target->query("stop_attack") != 0 ) extra += 5;
	if ( ! nullp(target->query_current_attacker() )) extra += 5;
	skill = (int) me->query_perm_skill("backstab");
	if ( ! skill ) return 0;
	level = skill/5 - (int)target->query_level() + 5;

	iq = (int)me->query_stat("int")-(int)target->query_stat("int");
	dex = (int)me->query_stat("dex")-(int)target->query_stat("dex");
	kar = (int)me->query_stat("kar")-(int)target->query_stat("kar");
	level = ( level < 0 ? 0 : level );
	level = ( level > 10 ? 10 : level );
	if ( extra > 30 ) extra = 30;
	rate = RATE[level] + kar + dex + iq + extra;

	if ( rate > 105 ) rate = 105;
	if ( wizardp(me) )
		write( sprintf("�ɹ��� = %d/130\n",rate) );
	if ( random(130) < rate )
		return 1;
	else
		return 0;
}

int cmd_backstab(string arg)
{
	object target,weapon;
	int delay;
	
	if ( (int)this_player()->query_temp("next_action") > time() )
		return notify_fail("( ����������ר������������ �� )\n");
	if ( ! arg ) return notify_fail("���뱳��˭��\n");
	if ( !(target = present( arg,environment(this_player()))) )
		return notify_fail("����û�н�"+arg+"�����\n");
	if ( target == this_player() )
		return notify_fail("�����Լ����㲻��ƴ suicide ��\n");
	if ( ! living(target) ) 
		return notify_fail("�������Ĵ���"
			+target->query("c_name")+"����ʲ����Ҳû������\n");
//	��Ȼ kill û����, ����Ҳ���˰�
//	if ( !visible(target,this_player()) || target->query("invisible_player") )
//		return notify_fail("���뱳��˭��\n");
	if ( !this_player()->query_vision() )
		return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");
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
	this_player()->set_temp("doing_backstab",1);
        this_player()->block_attack(4);
        this_player()->set_temp("msg_stop_attack",
                "( ����������ר�ĵȴ����̵�ʱ�����޷��������£� )\n" );
	delay = 2 + random(3) ;
        this_player()->set_temp("next_action",time()+delay);
	call_out("backstab_idle",delay,this_player(),target,
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
