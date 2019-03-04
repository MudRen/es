// holy_dagger.c

#include "../lilia.h"

inherit WEAPON;

void create()
{
    set_name("holy_dagger", "��ʥذ��");
    set_short("��ʥذ��");
    add("id", ({ "dagger" }));
    set_long(@C_LONG
����һ�ѵ���������ذ�ף�ذ��ɢ����ʥ��İ�ɫ��â����Ȼ���ذ�׿�����
�������������ǵ���������ʱ��������ԼԼ���ܵ�һ�������������
C_LONG
    );
    set("unit", "��");
    set("type", "dagger");
    set("weapon_class", 40);
    set("min_damage", 25);
    set("max_damage", 40);
    set("weight", 30);
    set("hit_func", "holy_power");
}

int holy_power(object victim, int damage)
{
    object me;
    int my_ali, vic_ali, dam, my_sp;

    if (!victim) return 0;
    if (!(me = environment(this_object())) || !living(me)) return 0;
    if (random(10) > 3) return 0;
    
    my_sp = (int)me->query("spell_points");
    if (my_sp < 10) return 0;

    my_ali = (int)me->query("alignment");
    vic_ali = (int)victim->query("alignment");
    
    if (my_ali < vic_ali && my_ali < 400)
    {
        tell_object(me, "��ʥذ���Ϸ���һ��������ȴ�˵������Լ���\n\n");
        me->receive_special_damage("divine", random(40));
        victim->set("last_attacker", me);
        return 0;
    }
    else 
    {
	dam = (my_ali - vic_ali) / 1000;
     	if (dam >= 50) dam = 50;
	me->set("spell_points", my_sp - 10);
        victim->receive_special_damage("divine", dam);
        victim->set("last_attacker", me);
	tell_object(me, set_color("\n�����ʥذ�׷���һ������������ˣ�\n\n", "HIY"));
        tell_room(environment(me), set_color("\n"+me->query("c_name")+"����ʥذ�׷���һ������������ˣ�\n\n", "HIY"), me);

        return dam;
    }
    return 0;
} 
