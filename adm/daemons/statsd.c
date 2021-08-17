//#pragma save_binary

// statsd.c
// This is the stats daemon. This object has the privilige to set player's
// level, attributes and experience.
// Created by Annihilator@Eastern.Stories 09-21-93
// Almost rewritten by Kyoko@Eastern.Stories.

#include <stats.h>
#include <daemons.h>
#include <uid.h>

nosave int *level_exp, *skill_exp, *stat_exp;

nosave string *stat_names = ({ "strength", "intelligence",
    "dexterity", "constitution", "piety", "karma", });

nosave string *special_defense_names = ({
    "fire", "cold", "electric", "energy", "mental", "acid",
    "poison", "magic", "evil", "divine", "none", });

void create()
{
    int i, exp;

    seteuid( ROOT_UID );
    level_exp = allocate(MAX_PLAYER_LEVEL);
    for( i = MAX_PLAYER_LEVEL-1, exp = WIZ_EXP; i >= 0; i--)
    {
        level_exp[i] = exp;
        exp -= exp / 3;
    }

    skill_exp = allocate(MAX_SKILL);
    for( i = MAX_SKILL-1, exp = MAX_SKILL_EXP; i >= 0; i--)
    {
        skill_exp[i] = exp;
        exp -= exp / 20;
    }

    stat_exp = allocate(MAX_ATTRIBUTE);
    for( i = MAX_ATTRIBUTE-1, exp = MAX_ATTR_EXP; i > 0; i--)
    {
        stat_exp[i] = exp;
        exp -= exp / 5;
    }
}

int clean_up() { return 0; }

nomask int valid_statsd_check(object ob)
{
    string euid;

    euid = geteuid(ob);
    if( euid == ROOT_UID ) return 1;
    if( member_group( euid, "admin" ) ) return 1;
    if( GUILD_D->is_guild(euid) ) return 1;
    return 0;
}

string *query_stat_names()
{
    return stat_names;
}

string *query_special_defense_names()
{
    return special_defense_names;
}

string check_stat_name(string arg)
{
    if( strlen(arg) == 3 ) {
        switch(arg) {
            case "str" : arg = "strength";     break;
            case "int" : arg = "intelligence"; break;
            case "dex" : arg = "dexterity";    break;
            case "con" : arg = "constitution"; break;
            case "pie" : arg = "piety";        break;
            case "kar" : arg = "karma";        break;
            default    : break;
        }
    }
    if( member_array(arg, stat_names) == -1 ) return 0;
    return arg;
}

int check_sepcial_defense_name(string arg)
{
    int i;

    i = member_array(arg, special_defense_names);
    if( i < 0 ) return 0;
    return i;
}

int advance_level(object player)
{
    int lvl;
//    write("advance level test1!\n");
    if( !valid_statsd_check(previous_object()) ) return 0;
//    write("advance level test2!\n");

    if( !living(player) || !userp(player) )
        return notify_fail("ֻ������������ȼ�!!\n");
//    write("advance level test3!\n");

    lvl = (int)player->query_level();
//    write("advance level test4!\n");
    if( lvl >= MAX_PLAYER_LEVEL )
        return notify_fail("��������������߼�����!!\n");

    notify_fail("��������, ��֪ͨ��ʦ!!\n");
    return ((int)player->set_level(lvl+1));
}

int advance_stat(object player, string arg)
{
    int stat;
//    write("advance stat test1!\n");

    if( !valid_statsd_check(previous_object()) ) return 0;
//    write("advance stat test2!\n");
    if( !living(player) || !userp(player) )
        return notify_fail("ֻ���������������!!\n");
//    write("advance stat test3!\n");
    if( !(arg=check_stat_name(arg)) ) return 0;
//    write("advance stat test4!\n");
    stat = player->query_perm_stat(arg);
    if( stat >= MAX_ATTRIBUTE ) return notify_fail(
        sprintf("��� %s(%s) �Ѵ����ֵ��!!\n", to_chinese(arg), arg) );
//    write("advance stat test5!\n");
    notify_fail("��������, ��֪ͨ��ʦ!!\n");
    return (int)player->set_perm_stat(arg, stat+1);
}

int train_skill(object player, string arg)
{
    int skill;

    if( !living(player) || !userp(player) )
        return notify_fail("ֻ���������������!!\n");

    skill = player->query_perm_skill(arg);

    if( skill >= MAX_SKILL ) return notify_fail(
        sprintf("�� %s(%s) �ļ����Դ����ֵ��!!\n", to_chinese(arg), arg) );

    notify_fail("��������, ��֪ͨ��ʦ!!\n");
    return (int)player->set_skill(arg, skill+1);
}

int query_level_exp(int level)
{
     if( level < 0 ) return -1;
    if( level >= MAX_PLAYER_LEVEL ) return -1;
    return level_exp[level];
}

int query_stat_exp(int value)
{
    if( value < 0 ) return -1;
    if( value >= MAX_ATTRIBUTE ) return -1;
    return stat_exp[value];
}

int query_skill_exp(int value)
{
    if( value < 0 ) return -1;
    if( value >= MAX_SKILL ) return -1;
    return skill_exp[value];
}

// This function returns 1 if the string is an approved skill.
int is_skill(string skill)
{
    return 1;
}

int change_perm_stat(object player, string arg, int stat)
{
    int limit;

    if( !valid_statsd_check(previous_object()) ) return 0;
    if( !living(player) ) return notify_fail("ֻ�������������!!\n");
    arg = check_stat_name(arg);
    if( !arg || arg == "" ) return 0;
    limit = player->query_user()? MAX_ATTRIBUTE : MAX_MONSTER_ATTRIBUTE;
    if( stat > limit )
        return notify_fail(sprintf("��Ǹ! ������: %d ��\n", limit));

    notify_fail("����ʧ��, ��֪ͨ��ʦ!!\n");
    return (int)player->set_perm_stat(arg, stat);
}

int change_skill(object player, string arg, int skill)
{
    if( !valid_statsd_check(previous_object()) ) return 0;
    if( !living(player) ) return notify_fail("ֻ��������м���!!\n");
    if( skill > MAX_SKILL )
        return notify_fail(sprintf("��Ǹ! ������: %d ��\n", MAX_SKILL));

    notify_fail("����ʧ��, ��֪ͨ��ʦ!!\n");
    return (int)player->set_skill(arg, skill);
}

string alignment_string(int align)
{
    if( align < -5000 ) return set_color("�����ӯ", "HIR");
    else if( align < -2500 ) return set_color("����", "HIR");
    else if( align < -1500 ) return set_color("ʮ����", "HIM");
    else if( align < -1000 ) return set_color("��������", "HIM");
    else if( align < -700 ) return set_color("������", "HIY");
    else if( align < -400 ) return set_color("���ж�״", "HIY");
    else if( align < -200 ) return set_color("���в���", "HIY");
    else if( align < 200 ) return set_color("�޹��޹�", "HIW");
    else if( align < 400 ) return set_color("������Ϊ", "HIG");
    else if( align < 700 ) return set_color("���пɼ�", "HIG");
    else if( align < 1000 ) return set_color("��������", "HIB");
    else if( align < 1500 ) return set_color("����Զ��", "HIB");
    else if( align < 2500 ) return set_color("�屡����", "HIB");
    else if( align < 5000 ) return set_color("��������", "HIC");
    else return set_color("һ������", "HIC");
}

string body_status_string(object obj)
{
    int percent, med, max;

    med = (int)obj->query("medication_resistance");
    max = (int)obj->query("critical_med_res");
    if( !max || max < 0 ) max = 1000;
    percent = 100 * med / max;
    if( percent < 20 ) return set_color("���������һ����������������", "HIC", obj);
    else if( percent < 40 ) return set_color("�����ͷ�е��Σ�����û��ʲ��󰭡�", "HIY", obj);
    else if( percent < 60 ) return set_color("�����ͷ�ؽ��ᡢȫ������Ҳ����ҩ��̫���ˡ�", "HIG", obj);
    else if( percent < 75 ) return set_color("�����ͷʹ���ѡ�ȫ��ֱð�亹������Ҹ��ط���Ϣһ�¡�", "HIM", obj);
    else if( percent < 90 ) return set_color("�����������ת����վ��վ���ȣ�����������˯��һ����", "HIR", obj);
    else return set_color("�����ȫ�����¶����Ծ���һ������Ҳû�С�", "HIC", obj);
}

varargs string status_string(object obj)
{
    int tar_hp, max_hp, percent;

    if( !obj ) obj = this_player();

    tar_hp = (int)obj->query("hit_points");
    max_hp = (int)obj->query("max_hp");
    if( !max_hp ) return set_color("״������", "HIR", obj);

    percent = 100 * tar_hp / max_hp;
        if (userp(obj)) {
    if( percent < 0 ) return sprintf("%s��", set_color("����", "HIR", obj));
    else if( percent < 10 ) return sprintf("�Ѿ�%s�ˡ�", set_color("����һϢ", "HIR", obj));
    else if( percent < 25 ) return sprintf("������Ѫ�����˼��أ�%s��", set_color("������Σ��", "HIM", obj));
    else if( percent < 40 ) return sprintf("���ϵ��������˿ڣ�%s��", set_color("Ѫ����ֹ", "HIY", obj));
    else if( percent < 60 ) return sprintf("�˵����ٵط���%s��", set_color("���������Ѫ", "HIY", obj));
    else if( percent < 80 ) return sprintf("���˼����ˣ�����%s��", set_color("û���˵�Ҫ��", "HIG", obj));
    else if( percent < 100 ) return sprintf("�ƺ����˵��ˣ�����%s��", set_color("����������Ҫ��", "HIG", obj));
    else return sprintf("���������%s��", set_color("���״����û������", "HIC", obj));
        } else {
    if( percent < 0 ) return "���ˡ�";
    else if( percent < 10 ) return "�Ѿ�����һϢ�ˡ�";
    else if( percent < 25 ) return "������Ѫ�����˼��أ�������Σ�ա�" ;
    else if( percent < 40 ) return "���ϵ��������˿ڣ�Ѫ����ֹ��" ;
    else if( percent < 60 ) return "�˵����ٵط������������Ѫ��" ;
    else if( percent < 80 ) return "���˼����ˣ�����û���˵�Ҫ����" ;
    else if( percent < 100 ) return "�ƺ����˵��ˣ����ǿ���������Ҫ����";
    else return "������������״����û�����ˡ�";
        }
}
varargs string c_status_string( object obj)
{
    return status_string(obj);
}
// changed by dola
// decrease losing levels from 1/10 to 1/20 when level is higher than 50
// harm 2 stats random selected from 6 stats. Not harm all stats now.
varargs void revive( object body, int skip )
{
    mapping skills;
    string *names;
    int foo1, foo2;
    int loop, attr, max;

    skills = (mapping)body->query_skills();
    names = keys(skills);


    if( !skip ) {
        for( loop=0, max=sizeof(names); loop<max; loop++ ) {
            if (skills[names[loop]]<=50) {
                body->set_skill(names[loop], skills[names[loop]]*9/10);
            } else {
                body->set_skill(names[loop], skills[names[loop]]*19/20);
            }
        }
        foo1=random(6);
        foo2=random(6);
        if (foo1 == foo2) foo1=(foo2+3) % 6 ;
        for( loop=0, max=sizeof(stat_names); loop<max; loop++ ) {
            if ( (loop!=foo1) && (loop!=foo2) ) continue;
            attr = (int)body->query_perm_stat(stat_names[loop]);
            if( attr < 2 ) continue;
            body->set_perm_stat(stat_names[loop], --attr);
        }
    }

    body->init_conditions();
    body->set("hit_points", 10);
    body->delete("spell_points");
    body->set("talk_points", 0);
    body->delete("force_points");
    body->set("medication_resistance", 0);
}
