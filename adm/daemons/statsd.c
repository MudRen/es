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
        return notify_fail("只有玩家能提升等级!!\n");
//    write("advance level test3!\n");

    lvl = (int)player->query_level();
//    write("advance level test4!\n");
    if( lvl >= MAX_PLAYER_LEVEL )
        return notify_fail("这是你能升的最高级数了!!\n");

    notify_fail("发生错误, 请通知巫师!!\n");
    return ((int)player->set_level(lvl+1));
}

int advance_stat(object player, string arg)
{
    int stat;
//    write("advance stat test1!\n");

    if( !valid_statsd_check(previous_object()) ) return 0;
//    write("advance stat test2!\n");
    if( !living(player) || !userp(player) )
        return notify_fail("只有玩家能提升属性!!\n");
//    write("advance stat test3!\n");
    if( !(arg=check_stat_name(arg)) ) return 0;
//    write("advance stat test4!\n");
    stat = player->query_perm_stat(arg);
    if( stat >= MAX_ATTRIBUTE ) return notify_fail(
        sprintf("你的 %s(%s) 已达最大值了!!\n", to_chinese(arg), arg) );
//    write("advance stat test5!\n");
    notify_fail("发生错误, 请通知巫师!!\n");
    return (int)player->set_perm_stat(arg, stat+1);
}

int train_skill(object player, string arg)
{
    int skill;

    if( !living(player) || !userp(player) )
        return notify_fail("只有玩家能提升技能!!\n");

    skill = player->query_perm_skill(arg);

    if( skill >= MAX_SKILL ) return notify_fail(
        sprintf("你 %s(%s) 的技能以达最大值了!!\n", to_chinese(arg), arg) );

    notify_fail("发生错误, 请通知巫师!!\n");
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
    if( !living(player) ) return notify_fail("只有生物才有属性!!\n");
    arg = check_stat_name(arg);
    if( !arg || arg == "" ) return 0;
    limit = player->query_user()? MAX_ATTRIBUTE : MAX_MONSTER_ATTRIBUTE;
    if( stat > limit )
        return notify_fail(sprintf("抱歉! 上限是: %d 。\n", limit));

    notify_fail("修正失败, 请通知巫师!!\n");
    return (int)player->set_perm_stat(arg, stat);
}

int change_skill(object player, string arg, int skill)
{
    if( !valid_statsd_check(previous_object()) ) return 0;
    if( !living(player) ) return notify_fail("只有生物才有技能!!\n");
    if( skill > MAX_SKILL )
        return notify_fail(sprintf("抱歉! 上限是: %d 。\n", MAX_SKILL));

    notify_fail("修正失败, 请通知巫师!!\n");
    return (int)player->set_skill(arg, skill);
}

string alignment_string(int align)
{
    if( align < -5000 ) return set_color("恶贯满盈", "HIR");
    else if( align < -2500 ) return set_color("罪大恶极", "HIR");
    else if( align < -1500 ) return set_color("十恶不赦", "HIM");
    else if( align < -1000 ) return set_color("恶名昭彰", "HIM");
    else if( align < -700 ) return set_color("作恶多端", "HIY");
    else if( align < -400 ) return set_color("恶行恶状", "HIY");
    else if( align < -200 ) return set_color("素行不良", "HIY");
    else if( align < 200 ) return set_color("无功无过", "HIW");
    else if( align < 400 ) return set_color("见义勇为", "HIG");
    else if( align < 700 ) return set_color("义行可嘉", "HIG");
    else if( align < 1000 ) return set_color("行侠仗义", "HIB");
    else if( align < 1500 ) return set_color("义名远播", "HIB");
    else if( align < 2500 ) return set_color("义薄云天", "HIB");
    else if( align < 5000 ) return set_color("功德无量", "HIC");
    else return set_color("一代大侠", "HIC");
}

string body_status_string(object obj)
{
    int percent, med, max;

    med = (int)obj->query("medication_resistance");
    max = (int)obj->query("critical_med_res");
    if( !max || max < 0 ) max = 1000;
    percent = 100 * med / max;
    if( percent < 20 ) return set_color("你觉得身体一切正常，精神饱满。", "HIC", obj);
    else if( percent < 40 ) return set_color("你觉得头有点晕，不过没有什麽大碍。", "HIY", obj);
    else if( percent < 60 ) return set_color("你觉得头重脚轻、全身乏力，也许是药吃太多了。", "HIG", obj);
    else if( percent < 75 ) return set_color("你觉得头痛欲裂、全身直冒冷汗，最好找个地方休息一下。", "HIM", obj);
    else if( percent < 90 ) return set_color("你觉得天旋地转，连站都站不稳，好想躺下来睡上一觉。", "HIR", obj);
    else return set_color("你觉得全身上下都不对劲，一点力气也没有。", "HIC", obj);
}

varargs string status_string(object obj)
{
    int tar_hp, max_hp, percent;

    if( !obj ) obj = this_player();

    tar_hp = (int)obj->query("hit_points");
    max_hp = (int)obj->query("max_hp");
    if( !max_hp ) return set_color("状况不明", "HIR", obj);

    percent = 100 * tar_hp / max_hp;
        if (userp(obj)) {
    if( percent < 0 ) return sprintf("%s。", set_color("死了", "HIR", obj));
    else if( percent < 10 ) return sprintf("已经%s了。", set_color("奄奄一息", "HIR", obj));
    else if( percent < 25 ) return sprintf("浑身是血，受伤极重，%s。", set_color("有生命危险", "HIM", obj));
    else if( percent < 40 ) return sprintf("身上到处都是伤口，%s。", set_color("血流不止", "HIY", obj));
    else if( percent < 60 ) return sprintf("伤到不少地方，%s。", set_color("流了许多鲜血", "HIY", obj));
    else if( percent < 80 ) return sprintf("受了几处伤，但都%s。", set_color("没有伤到要害", "HIG", obj));
    else if( percent < 100 ) return sprintf("似乎受了点伤，但是%s。", set_color("看起来并不要紧", "HIG", obj));
    else return sprintf("现在正处於%s。", set_color("最佳状况，没有受伤", "HIC", obj));
        } else {
    if( percent < 0 ) return "死了。";
    else if( percent < 10 ) return "已经奄奄一息了。";
    else if( percent < 25 ) return "浑身是血，受伤极重，有生命危险。" ;
    else if( percent < 40 ) return "身上到处都是伤口，血流不止。" ;
    else if( percent < 60 ) return "伤到不少地方，流了许多鲜血。" ;
    else if( percent < 80 ) return "受了几处伤，但都没有伤到要害。" ;
    else if( percent < 100 ) return "似乎受了点伤，但是看起来并不要紧。";
    else return "现在正处於最佳状况，没有受伤。";
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
