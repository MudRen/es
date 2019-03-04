//#pragma save_binary

#include <mudlib.h>

#define SCHOLAR_SUMMON_DIR "/d/scholar/demand/"
#define SCHOLAR_SUMMON_SKILL "demand/"
// ��Щ��������㶨�ģ���Ŀһ���Ϳ�����
#define spirits ({ "fire","water","dark","moon","wood","solid","sword",\
				"grass","solid2",})
#define names ({ "����","ˮ����","�ڰ�����","�¹⾫��","ľ����","��ؾ���",\
				"����","�ݾ���","��ؾ���2", })
#define files ({ "fire","water","dark","moon","wood","solid","sword","grass","solid2",})
#define levels ({ 13,10,17,15,8,19,16,4,19, })
#define combat ({ 1,0,1,0,1,1,1,0,1, })
#define cost_sp ({ 26,30,34,45,16,38,32,12,38, })

inherit DAEMON;

int help();
int can_summon(object me)
{
	mapping summon;
	string *type,str ;
	int i,j;

	if (!summon = me->query("demand")) {
		write("Ŀǰ���޷��ٻ��κζ�����\n");
		return 1;
	}
	str = "��Ŀǰ���ٻ��Ķ����� �� \n";
        type = keys(summon);
        for(i=0; i<sizeof(type); i++) {
        	j = member_array(type[i],spirits) ;
        	if ( j < 0 )
        		continue ;
         
          str += sprintf("  %-10s( %-10s)\t  %-10d\t  [%|6s] \n", names[j], 
          capitalize(type[i]),levels[j],
		( !combat[j]  ? "��սʱ" : "սʱ" ));
        }
        write(str);
        return 1;
}
	
int cmd_demand(string str)
{
	object me,victim;
	int i;

        if( !str ) return help();

        me = this_player();

	if ( str=="who" ) return can_summon(me);

	if (!me->query(SCHOLAR_SUMMON_SKILL+str)) 
             return notify_fail("�� ! ��ɵ�� !! �����ٻ����ֶ�����\n");
 
	i = member_array(str,spirits) ;
	if ( i < 0 )
                return notify_fail("�� ! ��ɵ�� !! �����ٻ����ֶ�����\n");

	if( (int)me->query("stop_attack")>0 )
		return notify_fail (
			"( ����һ��������û����ɣ��޷������� )\n");

	if( me->query_temp("summon_busy") )
    	  return notify_fail("��Ŀǰ��æ�����ո��ٻ����Ķ�����ͨ��û���������顣\n"); 

        if (me->query_temp("summon_rest"))
          return notify_fail("��ľ���������������������һ���ٻ�������Ϣһ�°ɡ�\n");

	if( environment(me)->query("no_summon"))
		return notify_fail( 
			"������Ҳ�������۾��������޷��������Ҫ�����ȥ��\n");

	if ( !combat[i] && me->query_attacker())
		return notify_fail("�㲻����ս�����ٻ�������� ...\n");

        if ( combat[i] && !me->query_attacker())
                return notify_fail("��ֻ����ս�����ٻ�������� ...\n");
//
	
        if ( (int)me->query_skill("polemic")< levels[i]*5 ) {
          write("��ı������ܲ�����ʹ"+names[i]+"�������㡣\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< levels[i]*3 ) {
          write("�������ѧ���ܲ�����ʹ"+names[i]+"�������㡣\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < cost_sp[i] ) {
	  write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
	  return 1;
	}
        me->add("spell_points",-cost_sp[i]);
        tell_object(me,set_color("�㼯�о���ʼ�������������ٻ�"+names[i]+"�������㡣\n","HIR"));
        me->set_temp("summon_busy",1);
        call_out("check_demand",1,me,i);
        return 1;
}
 
void check_demand(object me,int i)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic"))<=levels[i]) {
    write("���"+names[i]+"֮������鴫��û�гɹ�\���ٻ�ʧ�ܡ�\n");
    return ;
  }
  else {
    seteuid(getuid());
    mob=new("/d/scholar/demand/spirit/"+files[i]);
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
//    mob->set("max_hp","@@query_max_hp");
//    mob->set("hit_points","@@query_max_hp");
    mob->set_temp("master",me);
    mob->my_action(me);
    return;
  }
}

int help()
{
		write( @C_HELP
ָ���ʽ: demand <��������>

���ָ�����������ٻ��κ�Ը�������ľ���ǰ�����㡣
Ҫ��������������֮ǰ����Ҫ��취�����ǽ�����ϵ���������õĹ�ϵ��
�����Ƕ�������Ϊ����񣬲���ż����Щ�����ǻ������ȡһЩ���ۡ�

������� demand who ָ������ѯ����������Ķ���
C_HELP
		);
    return 1;
}
