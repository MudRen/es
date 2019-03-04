// RedWing.c		���֮��
//
//	Effect: blind
//	����ֻ����һ��
//
//			Lilia

#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

// default value
int toxic = 1;
int diff = 50;		// ʹ���Ѷ�

void create()
{
    set_name("red_wing", "���֮��");
    add("id", ({ "red_wing" }));
    set_short("���֮��");
    set_long("����һ����ҩ�ۣ������Ҫʹ�������ҩ���� poison <ĳ��>��\n");
    set("unit", "��");
}

void init()
{
    add_action("do_poison", "poison");
}

// refer to poison.c
// �¶�ʧ�� , return 1 else 0
int checkfault(object me,object target )
{
        int rate,level,iq,dex,skill,kar;
        skill = (int)me->query_skill("venomlogy");
        if ( skill == 0 )
                return 1;
        level = (int)me->query_level() - (int)target->query_level();
        iq = (int)me->query_stat("int") - (int)target->query_stat("int");
        kar = (int)me->query_stat("kar") - (int)target->query_stat("kar");
        dex = (int)me->query_stat("dex") - (int)target->query_stat("dex");
// 60 % skill , 18% level, 14% dex 19%kar, total 111
        rate = skill*3/5 + dex + kar + level + iq;
        if( random(rate) > diff )
                return 0;
        else
		return 1;
}

int do_poison(string arg)
{
        object user, dest, env;
        int i, n, degree;
        user = this_player();
	env = environment(user);

        if( !arg || arg=="" || ! (dest = present(arg,env)) )
                return notify_fail( "��Ҫ��˭�¶�? \n" );
        if( !living(dest) || dest == user )
                return notify_fail( "����� ? \n" );
        if ( dest->query("no_attack") )
                return notify_fail( "�㲻�ܶ���һ��¶���\n");
        if ( checkfault(user,dest) ) {
		tell_object(user, "�㽫����͵͵�ش���"+dest->query("c_name")+"���۾�.... ���Ǳ������ˣ�\n\n");
		tell_room(environment(user), user->query("c_name")+"��һ����̴���"+dest->query("c_name")+"....\n\n", ({user,dest}));
		tell_object(dest, user->query("c_name")+"��һ���̴����㣬��Ѹ�ٵرܿ�������Ļ��\n\n");

// �����ʧ����ҩ�����ʩ�ɹ�������ס������

	user->block_attack(2);

        } else {
		tell_object(user, "�㽫����͵͵�ش���"+dest->query("c_name")+"���۾�.... �ɹ��ˣ�\n\n");
                tell_room(environment(user), user->query("c_name")+"��֪����ʲ�᷽������"+dest->query("c_name")+"�����۾��ҽ�������\n\n", ({user,dest}));
                tell_object(dest, user->query("c_name")+"��һ���̴����㣬����۾���Ȼ�е�һ���ʹ��\n\n");

	degree = dest->query("blind") + 1;
    	if (degree > 10) degree = 10;
    	dest->set("blind", degree);

// ��ʧ������Ӽ���΢�Ķ��ԣ���Ȼû������ (ʧ��Ҫ��һ���̶����ϲ���Ч��)
// duration 8 damage 1

	(CONDITION_PREFIX + "simple_poison")->apply_effect(dest, 8, 1);

// ʩ������Ӫ���뽵��

	user->set("alignment",(int)user->query("alignment")-500);
        }
        //dest->kill_ob(user);
        user->kill_ob(dest);
	remove();
        return 1;
}
