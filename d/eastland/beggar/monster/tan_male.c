#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "sun male", "������" );
	add("id",({"sun","male"}) );
        set_short( "���ɽ���ƶ� ������" );
	set_long(@C_LONG
������ԼĪ������ʮ�����,�Զ�ʮ��ǰ�������¾����������Ⱦ��ڴ��ɽ���ƶ�
һֱδ����,��ؤ��������صظ����μ�ؤ������䡻���������µü�������
��������, �ϳ��������ޱȵ���ҩ ( herb ), �������������ҪҪ���Ƿ�����
����һЩ��
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set_natural_armor( 40 , 40 );
	set_natural_weapon( 50 , 25 , 33);
	set("max_hp",460);
	set("hit_points",460);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",20 );
	set_perm_stat( "int",25 );
	set_skill( "parry",30 );
	set_skill( "dodge",70 );
	set( "wealth/silver",1);
	set( "special_defense", ([ "all": 40,"none":40 ]) );
	set( "aim_difficulty",(["critical":100,"vascular":40,"weakest":40]) );
	set("couple",1);
        set_c_verbs( ({ "%sʹ�������򲻻��֡���һ��, ֻ������%s��",
                        "%s���һ�¡����򲻻��֡��ڶ���, ������%s׼������",
                        "%s���һ��,�����򲻻��֡���ǿһʽ�����Լ�����Ȼ����%s���˹�ȥ��"
                      }) ); 
        set( "chat_chance", 15 );
        set( "att_chat_output", ({
                 "������˵��:���˰�,������,�۸��������桫 \n"
        }) );
        equip_armor(DARMOR"tan_ring");
        set("inquiry", ([
             "herb":"@@ask_herb"
        ]) );
        set( "tactic_func", "my_attack" );
} 
void ask_herb(object asker)
{
write(@C_LONG
������˵��:��������һ�����ȵĵط�����һֻ�����ܡ�����,�⼸����ʧ����,
           ���ܰ����һ�����?
C_LONG
      );
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}
int accept_item(object me,object item)
{
    string name;
    name=item->query("name");
    if ((name!="fire toad")&&(name!="box")){
        tell_object(me,this_object()->query("c_name")+
              "˵��:���������������ﰡ?\n");
        item->move(me) ;
        return 1;
    }
    if (name=="fire toad"){
       tell_object(me,this_object()->query("c_name")+
              "�м���˵��:лл������һ���"+item->query("c_name")+
              "�����һ��,����һ��ҩ����\n"); 
       item->remove();
       call_out("recover",2,me);      
       return 1;
    }  
    if ( item->query("charge_times")<1){
       tell_object(me,this_object()->query("c_name")+
            "˵��:��,���С����̫���ˡ���\n");
       tell_object(me,this_object()->query("c_name")+
            "˵��˵�����������С�����ö���!!\n");
       item->remove();
       return 1;    
    }
    if (me->query("wealth/silver")<1500){
       tell_object(me,this_object()->query("c_name")+
              "˵��:������,����,������һǧ��ٴ��󡫡�\n");
       command("give box to "+me->query("name"));
       return 1;
    }
    me->add("wealth/silver",-1500); 
    item->set("times",10);
    item->add("charge_times",-1);
    tell_object(me,this_object()->query("c_name")+
              "˵��:����,���С������װ��������ҩ����\n"); 
    command("give box to "+me->query("name"));
    return 1;
}
void recover(object obj)
{
   object bonus;
   bonus=new(DITEM"box.c");
   bonus->move(this_object());
   tell_object(obj,this_object()->query("c_name")+
        "˵��:��,������������ҩ̫����,�Ұ�������С���������һЩ�ɡ�\n");
   command("give box to "+obj->query("name"));
}
int my_attack()
{ 
    object victim,*env,*couples;
    int i;
    
    victim = query_attacker();
    if( !victim ) return 0;

    env=all_inventory(environment(this_object()));
    couples = filter_array( env,"can_help", this_object() );
    for( i=0; i<sizeof(couples); i++ ) {
        tell_room( environment(this_object()), couples[i]->query("c_name")+
           "˵��:�������ǹ���,��������?\n",couples[i]);
        couples[i]->kill_ob(victim);
    }

    if  ( random(12)>1 )  return 0;
    else{
       tell_room( environment(this_object()),
           "������Ѹ�ٵشӻ���ȡ��һֻС��,�򿪺���,��ָմЩҩ��Ϳ���˿ڴ�!\n");
       for ( i=0;i<sizeof(env);i++) 
          if ( env[i]->query("couple") )      
            env[i]->receive_healing(20);  
       return 1;
   }      
}


