/* Wed  07-20-94 fixed.
special attack done: Sun  07-24-94
need clue...
*/
 
#include <mudlib.h>
/*#include <maze.c>*/
 
inherit MONSTER;
int sleep,clue,figure, power;
/* power=10 normal attack, little special attack.
         25 ok.. some special attack (used for shaking him up..)
         75 fierce attack.. if player k him while he's sleeping..
*/
 
void reset();
 
void create()
{
        ::create();
        set_level(4);
        set_name( "talus", "����˹" );
add("id",({"traveller"}));
        set_short( "@@short", "@@c_short" );
        set_long( "@@long", "@@c_long" );
        set( "race", "elf" );
        set( "gender", "male" );
        set( "alignment", 200 );
        set( "max_hp",100);
        set("hit_points",100);
        set_perm_stat("int",5);
        set_perm_stat("pie",10);
        set_perm_stat("dex",5);
        set_skill("dodge",50);
        set("wealth/silver",1);
        set_natural_weapon(10,2,10);
        set_natural_armor(10,1);
        set("weight",650);
        set("inquiry",([
        "gital": "@@ask_gital",
        "clue" : "@@ask_clue",
        "help" : "@@help_me",
        ]) );
        set("tactic_func","psionic");
        reset();
}
 
void reset()
{
/*    ::reset();*/
    sleep=1;
    clue=0;
    figure=1;
    power=10;
    write(can_read_chinese()?
    "����˹�������, ��������, \"û����? ����˯��.\"\n":
    "Talus looks around, yawning, \"Nothing else? Then I will sleep.\"\n");
    return;
}
 
int psionic()
{
    object victim;
    int chance, damage;
victim=query("last_attacker");
    if (!victim) {
        return 0;
    }
/* calculating chance of having special attack */
    chance=random(100)+1;
    if (chance<=power) { /* special attack */
        damage=random(power/5)+10;
/* pattern 1, psionic attack */
        if (random(1)+1) {
        write(can_read_chinese(victim)?
        "��Ȼ, �㷢���Լ�����һ����ɽ����, ���̵��ҽ��������ܷ�����.\n"+
        "����˹�����������Ժ�������: ����������... ������ڵ���.\n"+
        "ֻ��һ�����Ҵ���������. ����Ҫ����, ȴ�����Լ��޷�����.\n":
        "Suddenly, your surrounding changes: you are standing besides\n"+
        "a volcano, lava stirs around you. Talus speaks inside your mind:\n"+
        "Die! Die! Die!. You see lava moves towards you, and trying to\n"+
        "run away from it, but found you are unable to move.\n");
tell_room(environment(this_object()),({
        "�㿴��"+(string)victim->query("c_name")+"������վ��, �ƺ���ʲ��"+
        "��������ס��.\n",
        "You see "+(string)victim->query("cap_name")+" stands there idly."+
        " Seems to be distracted by something.\n" }),
        ({this_object(),victim}));
        victim->receive_damage(damage);
        return 1;
        }
/* pattern 2, the invisible air blade */
        else {
        tell_room(environment(this_object()),({
        "����˹�߾�˫��, ֻ�����ܵĿ���Ѹ�ٵ�����.\n",
        "Talus raises his hands, you see the air around him moved rapidly.\n"
        }), this_object());
        write(can_read_chinese(victim)?
        "һ�����εĵ��ݺݵؿ���������, ��ʹ���������.\n":
        "An invisible blade hacks you hard, you jerk and move backward.\n");
        tell_room(environment(this_object()),({
        (string)victim->query("c_name")+"����ʲ�ᶫ�������Ƶ�, ��ʹ���"+
        "������.\n",
        "You see "+(string)victim->query("cap_name")+" jerks backward in"+
" great pain, seems to be hitted by something.\n"}),({this_object(),victim}));
        victim->receive_damage(damage);
        return 1;
        }
    }
    return 0;
}
 
void ask_gital()
{
    if (sleep) {
        write(can_read_chinese()?
        "����˯��!\n":"He is sleeping.\n");
        return;
    }
    tell_room(environment(),({
        "Talus said: Gital? I am here because I want to get him out.\n"+
        "Talus sighs deeply.\n"+
        "But that evil mage is too powerful and sneaky, he said finally.\n",
        "����˹˵: Gital? ��֮���������������Ҫ��취����Ū����.\n"+
        "          ˭������ħŮ̫������....\n"+
        "����˹���ص�̾��һ����.\n"
        }), this_object());
        return;
}
 
void ask_clue()
{
    if (sleep) {
        write(can_read_chinese()?
        "����˯��!\n":"He is sleeping.\n");
        return;
    }
    tell_room(environment(),({
    "Talus shrugs, then said: sure, you can try to open the gate.\n"+
    "                         just follow the colors of the rainbow.\n",
    "����˹���ʼ�, ˵��: Ҳ��, �����԰�. ���ŷ���ʵ�ܼ�, �����ʺ�\n"+
    "                     ����ɫ׼û��.\n"
        }),this_object());
    clue=1;
        return;
}
 
void help_me(object who)
{
    if (sleep) {
        write(can_read_chinese()?
        "����˯��!\n":"He is sleeping.\n");
        return;
    }
    if (!clue) {
        tell_room(environment(),({
    "Talus said: why should I help you? Who do you think you are?\n",
    "����˹Ī������Ŀ�����˵��: �Ұ������?\n",
    }), this_object());
    return;
    }
    if (clue && figure) {
    tell_room(environment(),({
    "Talus sighs, \"Help you? I have a hard time to even help myself.\n"+
    "              but anyhow, here is a figure, maybe it will be of\n"+
    "              use to you. The name of the creature is Tio.\n",
    "����˹̾Ϣ��: ����? �Ҷ������ѱ���. ������, ������һ��С����.\n"+
    "              �����, ˵��������. �������ֽ� Tio.\n",
        }),this_object());
/*code to give the ppl who asked this question a figure*/
    figure=0;
        return;
    }
    else {
    tell_room(environment(), ({
    "Talus shakes his head helplessly and said, I wish I could help.\n"+
    "   but there is nothing I can do now.\n",
    "����˹ҡҡͷ��: ��Ҳ�������, ������ʵ��������Ϊ����.\n",
    }),this_object());
    return;
    }
}
 
void init()
{
    ::init();
    add_action("shake_me","shake");
    add_action("wake_me","wake");
}
 
int wake_me(string str)
{
    if (!str || str=="") {
        write(can_read_chinese()?
        "����˭?\n":"Wake who?\n");
        return 1;
    }
/* this part is really dumb... but heck.. if they killed him... */
    if (str!="talus") {
        write(can_read_chinese()?
        "��Ҫ���ѵ��˲�������.\n":
        "The one you want to wake up is not here.\n");
        return 1;
    }
    if (!sleep) {
        write(can_read_chinese()?
        "����˹�ܲ��ͷ���˵: ���������, �����¿콲��!\n":
        "Talus shouted to you: I am already awake! stat your business!\n");
        return 1;
    }
    write(can_read_chinese()?
    "��ҡҡ����˹, ֻ�������������������, ˵��: ������?\n":
    "You shaked Talus slightly. He awakes and sits up.\n"+
    "Then he looks at you, \"Looking for me?\"\n");
    tell_room(environment(),({
    (string)this_player()->query("name")+" wakes Talus up.\n",
    (string)this_player()->query("c_name")+"������˹����.\n"
    }), ({this_object(),this_player()}));
    sleep=0;
    return 1;
}
 
 
 
string short()
{
    if (sleep) {
        return "A sleeping traveller.";
    }
    return "Talus the adventurer.";
}
 
string c_short()
{
    if (sleep) {
        return "��˯�е�����.";
    }
    return "ð�ռ�����˹.";
}
 
string long()
{
    if (sleep) {
        return
"You see a well seasoned traveller sleeping in the corner. He\n"+
"looked so tired and skinny. Looks like he\'s been staying here\n"+
"for quiet some time.\n"; }
    return
"A tired adventurer. From his appearence you know he\'s been\n"+
"through a lot.\n";
}
 
string c_long()
{
    if (sleep) {
        return
"You see a well seasoned traveller sleeping in the corner. He\n"+
"looked so tired and skinny. Looks like he\'s been staying here\n"+
"for quiet some time.\n"; }
    return
"A tired adventurer. From his appearence you know he\'s been\n"+
"through a lot.\n";
}
 
int kill_ob(object victim)
{
    write(can_read_chinese()?
    "����˹��˯���о���, ���, ����, �ҳ���˯��ʱ����, ������!\n":
    "Talus jumps up, and yells, Go to HELL you jerk, dare you\n"+
    "attack me during my sleep!\n");
    sleep=0;
    power=75;
    ::kill_ob(this_player());
    return 1;
}
 
int shake_me(string str)
{
    if (!str || str=="") {
        return 0;
    }
    if (str!="talus") {
        return 0;
    }
    if (!sleep) {
        write(can_read_chinese()?
        "ι... ҡɶ��.. ���������! ����˹���ͷ���˵��.\n":
        "Talus shouted to you: I am already awake! Stop shaking me!\n");
        return 1;
    }
    write(can_read_chinese()?
    "��������İ�����˹ҡ��, ��һ����ˬ�Ŀ�����.\n":
    "Talus stares at you as you shakes him up violently.\n");
    tell_room(environment(),({
    "Talus awakes and stares at "+(string)this_player()->query("cap_name")+
    " angrily.\n",
    (string)this_player()->query("c_name")+" �����İ�����˹ҡ��, ֻ������˹һ����ˬ�ĵ�����.\n"
    }), ({this_object(),this_player()}) );
    tell_room(environment(), ({
    "Talus said coldly, \"stat your business and be gone.\"\n",
    "����˹�����˵��, \"������ҵ���Ҫ����?\"\n"
    }), this_object());
    power=25;
    return 1;
}
 
