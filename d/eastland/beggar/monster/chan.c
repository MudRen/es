#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "chan", "ȫִ��" );
	add( "id",({"chan"}) );
	set_short( "ȫִ��" );
	set_long(@C_LONG
ȫִ��ԭ��ؤ���Ĵ����ĵ���,����ǰΪ�˶�ȡ����֮λ��ϧ�������˴��ؤ�
���ұ��������Ƿ塻��ʱ����,���ҷ��������书��ȥ�˰���һ��ƽ١�ȫִ����
��֮���Ա�������������ȫ����������ǰ�Ĺ���,��Ȼ��ͻ�ȥ������Ѽ���ˡ���
���ڿ�������������ݺݵ�����һ�١� 
C_LONG	
        );
        set( "unit", "��" );
        set("hit_points",5000);
        set("max_hp",5000);
	set( "race","human");
	set( "gender", "male" );
	set( "alignment", -6000 );
	set( "wealth/gold", 10 );
        set("chat_chance",1);
        set_natural_armor(0,0);

        set("chat_output",({
          "ȫִ��˵��:��,������������Ĵ� ( mistake )��\n",
                                  }) );
        set("aim_difficulty",
          (["critical":120,"vascular":120,"weakest":120]) );
        set( "inquiry", ([
                  "mistake":"@@ask_mistake"
            ]) );
        set( "tactic_func", "cast_spell");
        
}

void ask_mistake(object asker)
{
   
   if ( ( !asker->query_temp("gonfu_asked") ) &&
        ( !asker->query_temp("jail_asked") ) ) {
      tell_object( asker,"ȫִ��˵��:�����ӷ�\n");  
      return ;
   }
   if ( this_object()->query("be_asked") )
     tell_object( asker,"ȫִ��˵��:�����ӷ�\n");
   else {
     tell_object( asker ,
        "ȫִ��˵��:��,�������Ĵ�?\n"
        "ȫִ�������̾��һ��������ע�������ϻ�����ǰ���¡�\n");
        call_out("recover1",10,asker);
        this_object()->set("be_asked",1);
        call_out("recover2",1800,this_object());
   }
}
void recover1( object asker )
{
   object ob1;
   
   tell_object( asker ,
      "ȫִ��̾��:ʮ������ǰ,����Ϊ����޹����ıȡ����֮λ,��ϧ������֮�����\n"
      "           ��������춱���������˲���,��Ӣ����ƽ�,����ȴ������������\n"
      "           ���ͷ�������һ������,���������಻����ϧһ�� ��������ֻ��һ\n" 
      "           ��Ը��;������������Ƕ���,���Ǽ�����������ǲ������ˡ�����\n"
      "           ����һ����,����ת�����ҵĶ��ӡ��������л,�����ӷ�\n"
      ); 
   ob1=new(DITEM"chan_letter.c");
   ob1->set("master",asker->query("name"));
   ob1->move(this_object());
   command("give chan letter to "+asker->query("name"));
} 
void recover2( object obj )
{
    obj->delete("be_asked");
}
int cast_spell()
{
    object victim;
      
       victim = query_attacker();
       if( !victim ) return 0;
       if ( ( random(10)>6 ) ){
          tell_room(environment(this_object()),
             "ȫִ��ӿڴ����ó���ҩ�Գ�......\n\n");
          this_object()->receive_healing(200);        
          victim->receive_damage(10);
          return 1;
       } return 0;   
}