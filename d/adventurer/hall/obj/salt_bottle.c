#include "mudlib.h"

inherit OBJECT;

void create()
{
     set_name("salt bottle","�ι�");
     set_short("�ι�");
     set_long("��������ʱ���ɻ�ȱ�İ��֣���������ʹʳ�������ζ������ʹʳ�ﳣ����\n"
     "�ʡ�����ι޾���װ���õģ�������춸������ܷ�ģ���Ҳ��֪�����滹\n"
     "�ж����Ρ�\n"
      );
     set("use_time",10);
     add("id",({ "bottle","salt" }) );
     set( "unit", "ƿ");
     set("weight",10);
     set("value", ({ 400, "silver" }));
}
void init()
{
	add_action("do_cook","cook");
}
int do_cook(string arg)
{
	int skill1,skill2;
	object me,target,env;
	me = this_player();
	skill1 = me->query_skill("anatomlogy");
	skill2 = me->query_skill("cook");
    	if ( !skill2 || skill2=0 ) 
    	        return notify_fail("�����ʲ��?");
    	if (!arg) return notify_fail("��Ҫ��ʲ�����չ¶���ɫ�ĳ��գ�\n");
	env = environment(me);
	if( !env || !target = present(arg, env) )
		return notify_fail("��Ҫ��⿵Ĳ��ϲ������\n");
        if ( !target->id("corpse")) {    
	  tell_object(me,"�������?�������������������!!\n");
	  tell_room( env, 
	             me->query("c_name")+"��Ȼ��ͼ��"+
	             target->query("c_name")+"��Ϊ����Ĳ��ϡ�\n", me);
	             return 1;
	                            }
	if ( !me->query_vision() )
        return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");
	if ( !present("carver",me) )
	        return notify_fail("�㻹��Ҫһ�Ѳ˵����ܱ����������ĳ��ա�\n");
	tell_object(me,
		set_color("���ͳ��ι޺Ͳ˵�������·�ߵ�ʬ���ԣ���ʼ��ϴ...\n","HIY") );
	tell_room(environment(me),sprintf("%s�ͳ�һ��С�˵���һ��С���ӣ��������Ķ���·�ߵ�ʬ���Ա�...",
		me->query("c_name")),
		me );
        target->remove();
        seteuid(getuid());
        call_out("cook",3,me);
        return 1;
} 
int cook(object me)
{
        object meat;
        int heal1,heal,skill1,skill2,level;
        
        skill1 = me->query_skill("anatomlogy");
        skill2 = me->query_skill("cook");
        level = me->query_level();
        heal1 = 7*skill2+2*skill1+3*level-random(10);
        heal = heal1/20;
        if ( !random(skill1)>9 ) 
                return notify_fail("����ͼ�ò˵�����ʬ����⣬ȴ�ѡ����ڵ���Ŀȫ��..\n");
        tell_object(me,
        "���ͳ��˵�������ʬ�����ϵ����⣬������һЩ�Σ���������Ǭ�⡣\n");
        tell_room(environment(me),"�㿴��" +me->query("c_name")+                
        "�ò˵���ʬ���ϵ���һƬƬ��������������������һЩ����...\n",me);
        meat = new("/d/adventurer/hall/obj/dry_meat");
        meat->set("heal",heal);
        if (skill2/2-random(5)<1) 
                 {
                 meat->set("rotten",1);
                 meat->move(me);
                 set("use_time",query("use_time")-1);
                 if ( query("use_time")<1 ) {
                       tell_object(me,
                       "�㷢���ι��Ѿ����ˣ������ְ�������·�ߡ�\n");
                       remove();
                       return 1;
                                            }
                 return 1;
                 }
        meat->move(me);
        set("use_time",query("use_time")-1);
        if ( query("use_time")<1 ) {
                        tell_object(me,
                        "�㷢���ι��Ѿ����ˣ������ְ�������·�ߡ�\n");
                        remove();
                        return 1;
                                   }
        return 1;
}
