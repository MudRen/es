//back_dragon.c

#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;

void create ()
{
        ::create();
        seteuid( getuid() );
   set_level(19);
   set_name( "back dragon", "����" );
        add ("id", ({ "bird", "dragon", }) );
   set_short( "����" );
        set_long( @C_LONG
    ��˵��а������飬ֻҪ�����֣���ؽ����ս����ƪ�������佫��Զ��
�������������������߳��֣��������������������ȥ��������а����۾���
���㣬���ϵ�����ٺ���Ц��
C_LONG
        );
   set( "alignment", 1000 );
    set( "unit", "��" );
   set_perm_stat( "dex", 30 );
   set_perm_stat( "str", 30 );
   set_perm_stat( "int", 30 );
   set_perm_stat( "con", 30 );
   set_perm_stat( "piety", 30 );
   set_perm_stat( "karma", 30 );
   set_natural_weapon( 100, 50, 88 );
   set_natural_armor( 100, 60 );
   setenv( "C_MIN", "һֻ$N�������һ��������");
        setenv( "C_MOUT", "$N��������$D��ȥ��");
        set ("special_defense",
            ([ "all" : 30 ]) );
        set ("wimpy", 100);
        set_skill( "dodge" ,100);
        set ("moving", 1);
        set ("speed", 20);
   set( "mountable", 0 );
   set( "max_load", 2200 );
   set( "c_extra_look", "$N������һ��������\n");
    set ("weight", 900);
   set( "exp_reward", 3333 );
    set ("time_to_heal", 5);
    set_c_verbs( ({ "%sײ��%s����", "%sһ������%s����", "%sһצץ��%s",
                    "%s�ô���ҧ%s", }) );
    set_c_limbs( ({ "����", "����", "����", "����", "��β", "��צ", }) );
    set( "c_death_msg", "%s˵: ���ǻ��ڵ�:( .... Ȼ������ˡ�\n" );
}

void init()
{
   npc::init();
   mount::init();
   add_action( "hit_enemy", "hit" );
}

int accept_item(object who,object item)
{
   object obj;
   obj = new( "/d/noden/moyada/obj/saliva" );

        tell_room( environment(),
             "�������һ��: ��....\n"
             "������"+item->query("c_name")+"һ�ڳԵ�!?\n" );
        item->remove();
        if( this_object()->query("mountable") ) {
            if( random(60)>1 ) return 0;
            tell_room( environment(),
            "����������һ̲��ˮ, ���డ!\n" );
            obj->move(environment(this_object()));
            return 1;
        }
        else {
            tell_object( who, "�����ڿ����������!\n" );
            set( "mountable", 1 );
            return 1;
        }
        return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()),
       "�������һ��: ��������ɱ��ħ��������!\n"
      ,  ({ this_object(), who }) );
    tell_object( who, "�������һ��: ��������ɱ��ħ��������!\n" );
    return 1;
}

int hit_enemy(string arg)
{
   object owner, target;

   owner = environment(this_object());

   if( !living(owner) )
        return notify_fail("�����������ָ�ӡ�\n");
   if( !arg ) return notify_fail("����ҧ˭��\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("����û�����ֶ�����\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("ҧ�Լ����������\n");
   if( !living(target) )
        return notify_fail("�����ſ�����������ҧ��"
                        +target->query("c_name")+"����ʲ����Ҳû������\n");
   if( !visible(target,owner) )
        return notify_fail("����ҧ˭��\n");
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
   if( target->query_temp("dodge_hit2") ) {
        tell_object( owner,
            "\n�����������Է�ҧȥ, ���ǵ���������!\n\n" );
        tell_object( target,
             "\n��������ҧ��, ������������!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"��������ҧ��"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
        tell_object( owner,
            "\n�����������Է����Ȳ�ҧȥ, ���˱�ҧȥ��һ����!\n\n" );
        tell_object( target,
            "\n���������Ȳ�ҧ��, �㱻ҧ����Ѫ���죬ˤ���ڵ�����!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"��������ҧ��"+target->query("c_name")+"�Ȳ�\n\n",
        ({ owner,target }) );
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( ���Ȳ����ˣ��޷������� )\n" );
        target->set_temp("dodge_hit2",1);
        return 1;
   }
   return 1;
}
//back_dragon.c

#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;

void create ()
{
        ::create();
        seteuid( getuid() );
   set_level(19);
   set_name( "back dragon", "����" );
        add ("id", ({ "bird", "dragon", }) );
   set_short( "����" );
        set_long( @C_LONG
    ��˵��а������飬ֻҪ�����֣���ؽ����ս����ƪ�������佫��Զ��
�������������������߳��֣��������������������ȥ��������а����۾���
���㣬���ϵ�����ٺ���Ц��
C_LONG
        );
   set( "alignment", 1000 );
    set( "unit", "��" );
   set_perm_stat( "dex", 30 );
   set_perm_stat( "str", 30 );
   set_perm_stat( "int", 30 );
   set_perm_stat( "con", 30 );
   set_perm_stat( "piety", 30 );
   set_perm_stat( "karma", 30 );
   set_natural_weapon( 100, 50, 88 );
   set_natural_armor( 100, 60 );
   setenv( "C_MIN", "һֻ$N�������һ��������");
        setenv( "C_MOUT", "$N��������$D��ȥ��");
        set ("special_defense",
            ([ "all" : 30 ]) );
        set ("wimpy", 100);
        set_skill( "dodge" ,100);
        set ("moving", 1);
        set ("speed", 20);
   set( "mountable", 0 );
   set( "max_load", 2200 );
   set( "c_extra_look", "$N������һ��������\n");
    set ("weight", 900);
   set( "exp_reward", 3333 );
    set ("time_to_heal", 5);
    set_c_verbs( ({ "%sײ��%s����", "%sһ������%s����", "%sһצץ��%s",
                    "%s�ô���ҧ%s", }) );
    set_c_limbs( ({ "����", "����", "����", "����", "��β", "��צ", }) );
    set( "c_death_msg", "%s˵: ���ǻ��ڵ�:( .... Ȼ������ˡ�\n" );
}

void init()
{
   npc::init();
   mount::init();
   add_action( "hit_enemy", "hit" );
}

int accept_item(object who,object item)
{
   object obj;
   obj = new( "/d/noden/moyada/obj/saliva" );

        tell_room( environment(),
             "�������һ��: ��....\n"
             "������"+item->query("c_name")+"һ�ڳԵ�!?\n" );
        item->remove();
        if( this_object()->query("mountable") ) {
            if( random(60)>1 ) return 0;
            tell_room( environment(),
            "����������һ̲��ˮ, ���డ!\n" );
            obj->move(environment(this_object()));
            return 1;
        }
        else {
            tell_object( who, "�����ڿ����������!\n" );
            set( "mountable", 1 );
            return 1;
        }
        return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()),
       "�������һ��: ��������ɱ��ħ��������!\n"
      ,  ({ this_object(), who }) );
    tell_object( who, "�������һ��: ��������ɱ��ħ��������!\n" );
    return 1;
}

int hit_enemy(string arg)
{
   object owner, target;

   owner = environment(this_object());

   if( !living(owner) )
        return notify_fail("�����������ָ�ӡ�\n");
   if( !arg ) return notify_fail("����ҧ˭��\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("����û�����ֶ�����\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("ҧ�Լ����������\n");
   if( !living(target) )
        return notify_fail("�����ſ�����������ҧ��"
                        +target->query("c_name")+"����ʲ����Ҳû������\n");
   if( !visible(target,owner) )
        return notify_fail("����ҧ˭��\n");
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
   if( target->query_temp("dodge_hit2") ) {
        tell_object( owner,
            "\n�����������Է�ҧȥ, ���ǵ���������!\n\n" );
        tell_object( target,
             "\n��������ҧ��, ������������!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"��������ҧ��"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
        tell_object( owner,
            "\n�����������Է����Ȳ�ҧȥ, ���˱�ҧȥ��һ����!\n\n" );
        tell_object( target,
            "\n���������Ȳ�ҧ��, �㱻ҧ����Ѫ���죬ˤ���ڵ�����!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"��������ҧ��"+target->query("c_name")+"�Ȳ�\n\n",
        ({ owner,target }) );
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( ���Ȳ����ˣ��޷������� )\n" );
        target->set_temp("dodge_hit2",1);
        return 1;
   }
   return 1;
}
