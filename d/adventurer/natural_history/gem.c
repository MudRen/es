#include <mudlib.h>

#define SCHOLAR_SUMMON_DIR "/d/scholar/demand/"
#define SCHOLAR_SUMMON_SKILL "demand/"
// ��Щ��������㶨�ģ���Ŀһ���Ϳ�����
#define spirits ({ "fire","water","dark","moon","wood","solid","grass" })
#define names ({ "����","ˮ����","�ڰ�����","�¹⾫��","ľ����","��ؾ���","�ݾ���" })

#define files ({ "fire","water","dark","moon","wood","solid","grass"})
#define levels ({ 13,10,17,15,8,19,4 })
#define combat ({ 1,0,1,0,1,1,0 })
#define cost_sp ({ 13,15,17,23,8,19,6 })
#define stone ({ "ruby","sapphire","obsidian","crystal","agate","diamond","emerald"})
#define c_stone ({ "�챦ʯ","����ʯ","����ʯ","ˮ��","���","��ʯ","���"})
#define need_str ({ 15,12,17,11,9,19,10 })
#define damage ({ 10,3,15,2,7,20,1 })

inherit OBJECT;
inherit DAEMON;

void create()
{
	int i;
	
	i = random(7);
	set_name(stone[i],c_stone[i]);
	set_short(stone[i],c_stone[i]);
	add( "id" , ({ stone[i] }) );
	set_long( 
		"����һ��������"+c_stone[i]+"�������ȥ���Ӧ������������\n"
		"�ļ�Ǯ����֪����������һ�����������������������ı�ʯ��\n"
	        "ֻ�а׳ղŻ�����洦�Ҷ�(throw)��??\n"
	);
   	set("unit","��");
   	set("no_sale",1);
   	set("weight", 20);
   	set("need_skill",(levels[i]+1)*4);
   	set("value",({ cost_sp[i]*300 , "silver" }) );
}
void init()
{
        add_action( "cmd_throw", "throw" );
}

int cmd_throw(string arg)
{
	object target,me,victim;
	string type,who,what;
	int i;

	type = this_object()->query("name");
	i = member_array(type,stone) ;
	me = this_player();
	if ( ! arg ) return notify_fail("��ʲ��? ������??\n");
	if( sscanf( arg, "%s to %s",what,who )==2 ) {
	if ( !(target = present( who,environment(this_player()))) )
		return notify_fail("����û�н�"+who+"�Ķ�����\n");
	if ( this_player()->query("class") != "adventurer" )
	        return notify_fail("���������Ķ����������Ҫ����������?\n");
	if ( what != stone[i] )
	        return notify_fail("��ȷ���Ƕ�"+what+"��?\n");  
	if ( ! living(target) ) { 
		write("�������İ�"+c_stone[i]+"����"
			+target->query("c_name")+"������"+c_stone[i]+"�������⣬ʲ����Ҳû������\n");
	        remove();
	        return 1;
	        }
	if ( !visible(target,this_player()) || target->query("invisible_player") )
		return notify_fail("������"+c_stone[i]+"����˭?\n");
	if ( !this_player()->query_vision() )
		return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");

	if( (int)me->query("stop_attack")>0 )
		return notify_fail (
			"( ����һ��������û����ɣ��޷������� )\n");

	if( me->query_temp("aim_busy") )
    	  return notify_fail("��Ŀǰ��æ����׼���Ŀ�꣬û����������顣\n"); 

	if ( (int)me->query("spell_points") < cost_sp[i] ) {
	  write("��ľ���״��������ʹ����׼Ŀ�ꡣ\n");
	  return 1;
	}
        me->add("spell_points",-cost_sp[i]);
        tell_object(me,set_color("�㼯�о���ʼע��"+target->query("c_name")+"��һ��һ����\n","HIR"));
        me->set_temp("aim_busy",1);
        call_out("check_demand",1,me,target,i);
        return 1;
        }
        return notify_fail("��ʲ��? ������??\n");
} 
void check_demand(object me,object target,int i)
{
  object mob;

  me->delete_temp("aim_busy");
        if( environment(me)->query("no_summon")) {
        write("�������İ����"+c_stone[i]+"����ȥ�������������������⣬ʲ���¶�û������\n");
        remove();
        return ;
        }
    if ( (int)me->query_perm_stat("str") < need_str[i]) {
    write("���"+c_stone[i]+"����ȥ������ʲ�ᶼû��������Ͽ�����������\n");
    me->set("stop_attack",3);
    return ;
  }
    
    if ( !combat[i] && target->query_attacker()) {
	write("���"+c_stone[i]+"����ȥ�������������������⣬ʲ�ᶼû����\n");
        remove();
        return ;
        }
        if ( combat[i] && !target->query_attacker()) {
        write("���"+c_stone[i]+"����ȥ�������������������⣬ʲ�ᶼû����\n");  
        remove();
        return ;
        }
  else {
    seteuid(getuid());
    write("���"+c_stone[i]+"����"+target->query("c_name")+"��һ����������"
          "���ᣬһ��"+names[i]+"����Ƭ�г���......\n");
    mob = new("/d/scholar/demand/spirit/"+files[i]);
// ȥ����ս���޹ص��趨
    mob->set_perm_stat("str",random((int)me->query_perm_stat("str")*2/3)+levels[i]);
//    mob->set_perm_stat("int",random((int)me->query_perm_stat("int")*2/3)+levels[i]);
    mob->set_perm_stat("kar",random((int)me->query_perm_stat("kar")*2/3)+levels[i]);
//    mob->set_perm_stat("con",random((int)me->query_perm_stat("con")*2/3)+levels[i]);
    mob->set_perm_stat("dex",random((int)me->query_perm_stat("dex")*2/3)+levels[i]);
//    mob->set_perm_stat("pie",random((int)me->query_perm_stat("pie")*2/3)+levels[i]);
    mob->set_natural_weapon((int)me->query("weapon_class1")+levels[i],levels[i],(int)me->query("max_damage1")*3/5+levels[i]);
//    mob->set_temp("extra_ac",(int)me->query("armor_class")+levels[i]);
//    mob->set_temp("extra_db",(int)me->query("defense_bonus")+levels[i]);
    mob->set_skill("unarmed",100);
//    mob->set("max_hp","@@quer2y_max_hp");
//    mob->set("hit_points","@@query_max_hp");
    mob->set_temp("master",target);
    mob->my_action(target);
    target->receive_damage(damage[i]);
    remove();
    return;
  }
}

