#include <mudlib.h>

inherit "/d/eastland/liang_shan/magic";
inherit OBJECT;

void init()
{
	add_action( "throw_stone", "throw" );
}

void create()
{
	set_name("stone","Сʯ��");
	set_short("Сʯ��");
	set_long(
		"һ���洦�ɼ���СԲʯ��������Ӳ�ģ�����������һ����ʹ�ġ�\n"
	);
   	set("unit","��");
   	set("weight", 10);
   	set("value",({ 1, "silver" }) );
}
int throw_stone(string arg)
{
        string s1,s2;
        object target,owner;

        if (!arg) {
                return notify_fail(
                        "��ʲ�ᶪȥ��?\n");
                }
        sscanf(arg, "%s to %s", s1, s2);
        if ((!s1) || (lower_case(s1) != "stone"   )) {
                return notify_fail( 
                        "��Ҫ��ʲ����?\n");
                }
        if (!s2) {
                return notify_fail( 
                        "��Ҫ��ʯͷ��˭?\n");
                }

        target = present(s2,environment(this_player()));
        
        if ( (!target) ||
                ( environment(target)!=environment(this_player()) ) ) {
                return notify_fail( 
                        "������������!\n");
                }
        if ( target->query("no_attack") ) {
                 return notify_fail("��һ����ɱ��\n");
                }
        if ( userp(target) ) {
                     if ( (int)target->query_level()< 5 ||
                      (int)this_player()->query_level()<5 )
                     return notify_fail("�㲻�� PK �� !!\n");
                     }
        
        if (target == this_player()) {
                return notify_fail( 
                        "��ʯͷ���Լ�?\n");
                }
		write("��������İ�ʯͷ����"+target->query("c_name")+"��\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+
			"�ӻ����ͳ�һ��ʯͷ���������Ķ���"+target->query("c_name")+"\n" , this_player()
		);
		target->receive_damage( this_player()->query_perm_stat("str")/2+random(5) );
                this_player()->gain_experience(20);
                this_player()->add("alignment",-10);
                target->set("last_attacker",this_player());
                target->kill_ob(this_player());
                report(this_player(),target);
	remove();
	return 1;
}
