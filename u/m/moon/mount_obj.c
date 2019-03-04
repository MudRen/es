// This is the mount object, inherited by monsters can be mounted.
// By Ruby@ES 1995-6-18

#include <mudlib.h>
inherit OBJECT;
int hit1(string arg);
void create()     
{
        if (clonep(this_object())) {
                set_default_ob("/std/mount_obj");
                return ;
        }
        set_name( "wooden horse", "Сľ��" );
        set("short", "Сľ��");
        set("long", "����һƥľ��");
        set( "unit", "ƥ" );
        set("weight", 0);
        set("prevent_drop",1);
        set("prevent_insert",1);
}

void init()
{
        add_action( "do_dismount", "dismount" );
        add_action( "do_hit","hit");
}

int do_dismount()
{
        return call_other("/adm/daemons/mount","dismount",this_object(),this_player());
}

int scare_me()
{
        return "/adm/daemons/mount"->scare_me(this_object());
}
int do_hit(string arg)
{
   if(this_object()->query("name")=="chocobo" ||
      this_object()->query("name")=="black chocobo") return hit1(arg);
   return 0;
}

int hit1(string arg)
{
   object owner, target,me;
   int rid,deb,dod,dam;

   owner = environment(this_object());
   me=this_object();

   if( !living(owner) ) 
        return notify_fail("���������ָ�ӡ�\n");
   if( !arg ) return notify_fail("����ײ˭��\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("����û�����ֶ�����\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("ײ�Լ����������\n");
   if( !living(target) )
        return notify_fail("�������������ײ��"
                        +target->query("c_name")+"����ʲ����Ҳû������\n");
   if( !visible(target,owner) )
        return notify_fail("����ײ˭��\n");
   if( !owner->query_vision() )
        return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");
   if ( target->query("no_attack") )
        return notify_fail("��һ����ɱ��\n");
   if( userp(target) && (int)target->query_level()< 5 )
        return notify_fail("�㲻�� PK �� !!\n");
   if( "berserk" == (string)owner->query("tactic") )
        return notify_fail("����뻻��һ��ս����\n");
   if( "melee" == (string)owner->query("tactic") )
        return notify_fail("����뻻��һ��ս����\n");
   if( "assault" == (string)owner->query("tactic") )
        return notify_fail("����뻻��һ��ս����\n");
   if( (int)owner->query("talk_points")<100 )
        return notify_fail("��Ľ�̸����̫����!\n" );
   if( owner->query_skill("riding")/2 +
        random( owner->query_skill("riding")/2)
      < ( int )target->query_skill("dodge")  ) {

        tell_object( owner,
            "\n������"+me->query("c_name")+"��Է�ײȥ, ���ǵ���������!\n\n" );
        tell_object( target,
             "\n"+me->query("c_name")+"����ײ��, ������������!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"����"+me->query("c_name")
             +"ײ��"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
      if(me->query("name")=="black chocobo")
      {
         rid = (int)owner->query_skill("riding");
         deb = (int)target->query("defense_bonus");
         dod = (int)target->query_skill("dodge");
         dam = rid/2 - deb/5 -random(dod)/5;
         tell_object( owner,
         "\n�������ɫ½������Է�ײȥ, ����ˤ���ڵ�, �ƺ��ܵ��޴���˺�!\n\n" );
         tell_object( target,
          "\n��ɫ½��������ײ��, ��ˤ���ڵ�, �ƺ��ܵ��޴���˺�!\n\n" );

         target->add("hit_points",-dam);
         owner->add("talk_points",-20);
       }
      else
       {
         tell_object( owner,
            "\n������"+me->query("c_name")+"��Է�ײȥ, ����ˤ���ڵ�����!\n\n" );
         tell_object( target,
            "\n"+me->query("c_name")+"����ײ��, ��ˤ���ڵ�����!\n\n" );
         tell_room( owner,
            owner->query("c_name")+"����"+me->query("c_name")+
            "ײ��"+target->query("c_name")+"\n\n",
         ({ owner,target }) );
        }
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( ������ˤ���ڵأ��޷������� )\n" );
        return 1;
   }
   return 1;
}
