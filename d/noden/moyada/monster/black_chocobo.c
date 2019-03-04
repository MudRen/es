//black_chocobo.c

#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;

void create ()
{
	::create();
	seteuid( getuid() );
   set_level(18);
	set_name( "black chocobo", "��ɫ½����" );
	add ("id", ({ "bird", "chocobo", }) );
	set_short( "��ɫ½����" );
	set_long( @C_LONG
���ֵ�½���񣬲��������ڵ����ܣ������ڿ��зɡ���ϧ�����ٶȲ�����
�ܿ죬ʱ�ٴ�Լֻ����ʮ�������ƴ���������ӣ��������ˡ�
��˵����ʳ�κζ����������������������, �������ײ��(hit)���ˡ�
C_LONG
	);
   set( "alignment", 1500 );
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 30 );
   set_perm_stat( "str", 25 );
   set_perm_stat( "int", 13 );
   set_perm_stat( "con", 25 );
	set_perm_stat( "piety", 25 );
	set_perm_stat( "karma", 30 );
   set_natural_weapon( 40, 20, 40 );
   set_natural_armor( 100, 50 );
	setenv( "C_MIN", "ͻȻһֻ$N���ٵط��˽�����");
	setenv( "C_MOUT", "$N�����$D�߷����ˡ�");
	set ("special_defense",
	    ([ "all" : 25 ]) );
	set ("wimpy", 100);
	set_skill( "dodge" ,100);
	set ("moving", 1);
	set ("speed", 5);
   set( "mountable", 0 );
   set( "max_load", 2400 );
   set( "c_extra_look", "$N������һֻ��ɫ½����\n");
    set ("weight", 900);
   set( "exp_reward", 5555 );
    set ("time_to_heal", 5);
    set_c_verbs( ({ "%sײ��%s����", "%sһ������%s����", "%sһצץ��%s",
                    "%s�ô�����%s", }) );
    set_c_limbs( ({ "����", "���", "��", "��", "ƨ��", "צ��", }) );
    set( "c_death_msg", "%s˵: ����#@!&$*? :( .... Ȼ������ˡ�\n" );
}

void init()
{
//      monster::init();
   add_action( "hit_enemy", "hit" );
   mount::init();
}

int accept_item(object who,object item)
{
   object obj;
   obj = new( "/d/noden/moyada/obj/saliva" );

        tell_room( environment(),
            "��ɫ½������һ��: GEEE....\n"
            "��ɫ½�����"+item->query("c_name")+"���¶�!?\n" );
        item->remove();
        if( this_object()->query("mountable") ) {
            if( random(60)>1 ) return 0;
            tell_room( environment(),
            "��ɫ½���������һ̲��ˮ, ���డ!\n" );
            obj->move(environment(this_object()));
            return 1;
        }
        else {
            tell_object( who, "�����ڿ������ɫ½������!\n" );
            set( "mountable", 1 );
            return 1;
        }
        return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()),
      "��ɫ½������һ��: ���� "+who->query("c_name")+" ��ɱ��ħ������!\n"
      ,  ({ this_object(), who }) );
    tell_object( who, "��ɫ½������һ��: ��������ɱ��ħ������!\n" );
    return 1;
}

int hit_enemy(string arg)
{
   object owner, target;
   int rid, deb, dod, dam;

   owner = environment(this_object());

   if( !living(owner) ) 
        return notify_fail("��ɫ½���������ָ�ӡ�\n");
   if( !arg ) return notify_fail("����ײ˭��\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("����û�����ֶ�����\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("ײ�Լ����������\n");
   if( !living(target) )
        return notify_fail("��ɫ½����������ײ��"
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
   if( "flank" == (string)owner->query("tactic") )
        return notify_fail("����뻻��һ��ս����\n");
   if( (int)owner->query("talk_points")<100 )
        return notify_fail("��Ľ�̸����̫����!\n" );
   if( (int)target->query("hit_points")<50 )
        return notify_fail("��ɫ½����м�۸���˲���һ���ļһ\n");

   if( target->query_temp("dodge_hit") ) {
        tell_object( owner,
            "\n�������ɫ½������Է�ײȥ, ���ǵ���������!\n\n" );
        tell_object( target,
            "\n��ɫ½��������ײ��, ������������!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"������ɫ½����ײ��"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
   rid = (int)owner->query_skill("riding");
   deb = (int)target->query("defense_bonus");
   dod = (int)target->query_skill("dodge");
   dam = rid/2 - deb/5 -random(dod)/10;
        tell_object( owner,
            "\n�������ɫ½������Է�ײȥ, �����ƺ��ܵ��޴���˺�!\n\n" );
        tell_object( target,
            "\n��ɫ½��������ײ��, ���ƺ��ܵ��޴���˺�!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"������ɫ½����ײ��"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points",-100);
        target->add("hit_points",-dam);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->set_temp("dodge_hit",1);
        return 1;
   }
   return 1;
}
