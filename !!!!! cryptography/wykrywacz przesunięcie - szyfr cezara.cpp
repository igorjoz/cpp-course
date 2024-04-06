#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int const ALPHABET_LETTERS_QUANTITY = 26;

string decryptCeasarsCode(string encryptedText, int shift) {
    transform(encryptedText.begin(), encryptedText.end(), encryptedText.begin(), [](char c) { return tolower(c); });
    string decryptedText = "";

    for (int i = 0; i < encryptedText.length(); i++) {
        int charIntValue = (int)(encryptedText[i]);

        if (charIntValue >= 97 + shift and charIntValue <= 122) {
            decryptedText += (char)(charIntValue - shift);
        }
        else if (charIntValue >= 97 and charIntValue < 97 + shift) {
            decryptedText += (char)(122 - shift + (charIntValue - 97) + 1);
        }
        else {
            decryptedText += encryptedText[i];
        }
        //cout << encryptedText[i] << "-->" << decryptedText[i] << "   ";
    }

    return decryptedText;
}

int main()
{
    // some encrypted, long enough text (more is better), variety of words (is text is artificial it probably won't work)
    //string sample1 = "First, let's define what lockdown is. My understanding is: temporary (let's say up to 1 year) strong constraints on the human rights & economy in order to prevent something - in our case it's getting infected by coronavirus. Now, when great quantities of people are infected(and they even might not know about that, but still spread the virus) and the epidemic affects pretty every place in Poland, getting infected isn't that hard - there's high risk of getting infected. It's obvious that for the stateand public healthcare system, prevention is way cheaper than helping sick people in hospitals after infection.But the thing is : what's more important - maintaining the stability of the public healthcare or maintaining common rights and not destabilizing the whole economy(simply saying : leaving as it was before).I will consider that later. Lockdown is about manipulating people's behavior in many possible ways to make them less mobile and make them meet less people, so possibility of getting infected is smaller. Should the authorities introduce restrictions like this? In my opinion the answer isn't simple yes or no. It should depend on the current situation. Let's see what factors are important and explain them. My final conclusion is that we should push our health system to the limit and try not to violate basic rights. In my opinion we shouldn't let people die because there was no place for them in hospital, so I agree on some restrictions (if they are needed), but only those that are the most effective and the least harmful like wearing masks in places where there are many people and definitely reject irrational ideas like prohibiting people entering forests or prohibiting kids from going out without an adult.";
    //string sample2 = "First, let’s define what “lockdown” is. My understanding is: temporary (let’s say up to 1 year) strong constraints on the human rights & economy in order to prevent something - in our case it’s getting infected by coronavirus.";
    //string sample3 = "Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32.' The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested.Sections 1.10.32 and 1.10.33 from de Finibus Bonorum et Malorum by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H.Rackham."

    //string text = "First, let's define what lockdown is. My understanding is: temporary (let's say up to 1 year) strong constraints on the human rights & economy in order to prevent something - in our case it's getting infected by coronavirus. Now, when great quantities of people are infected(and they even might not know about that, but still spread the virus) and the epidemic affects pretty every place in Poland, getting infected isn't that hard - there's high risk of getting infected. It's obvious that for the stateand public healthcare system, prevention is way cheaper than helping sick people in hospitals after infection.But the thing is : what's more important - maintaining the stability of the public healthcare or maintaining common rights and not destabilizing the whole economy(simply saying : leaving as it was before).I will consider that later. Lockdown is about manipulating people's behavior in many possible ways to make them less mobile and make them meet less people, so possibility of getting infected is smaller. Should the authorities introduce restrictions like this? In my opinion the answer isn't simple yes or no. It should depend on the current situation. Let's see what factors are important and explain them. My final conclusion is that we should push our health system to the limit and try not to violate basic rights. In my opinion we shouldn't let people die because there was no place for them in hospital, so I agree on some restrictions (if they are needed), but only those that are the most effective and the least harmful like wearing masks in places where there are many people and definitely reject irrational ideas like prohibiting people entering forests or prohibiting kids from going out without an adult.";
    //string text = "vyhij, buj’i tuvydu mxqj “besatemd” yi. co kdtuhijqdtydw yi: jucfehqho (buj’i iqo kf je 1 ouqh) ijhedw sedijhqydji ed jxu xkcqd hywxji & usedeco yd ehtuh je fhuludj iecujxydw - yd ekh sqiu yj’i wujjydw ydvusjut ro sehedqlyhki.";
    string text = "jvuayhyf av wvwbshy ilsplm, svylt pwzbt pz uva zptwsf yhukvt alea. pa ohz yvvaz pu h wpljl vm jshzzpjhs shapu spalyhabyl myvt 45 ij, thrpun pa vcly 2000 flhyz vsk. ypjohyk tjjspuavjr, h shapu wyvmlzzvy ha ohtwklu-zfkulf jvsslnl pu cpynpuph, svvrlk bw vul vm aol tvyl vizjbyl shapu dvykz, jvuzljalaby, myvt h svylt pwzbt whzzhnl, huk nvpun aoyvbno aol jpalz vm aol dvyk pu jshzzpjhs spalyhabyl, kpzjvclylk aol bukvbiahisl zvbyjl. svylt pwzbt jvtlz myvt zljapvuz 1.10.32 huk 1.10.33 vm kl mpupibz ivuvybt la thsvybt (aol leayltlz vm nvvk huk lcps) if jpjlyv, dypaalu pu 45 ij. aopz ivvr pz h aylhapzl vu aol aolvyf vm laopjz, clyf wvwbshy kbypun aol yluhpzzhujl. aol mpyza spul vm svylt pwzbt, svylt pwzbt kvsvy zpa htla.., jvtlz myvt h spul pu zljapvu 1.10.32.' aol zahukhyk jobur vm svylt pwzbt bzlk zpujl aol 1500z pz ylwyvkbjlk ilsvd mvy aovzl pualylzalk.zljapvuz 1.10.32 huk 1.10.33 myvt kl mpupibz ivuvybt la thsvybt if jpjlyv hyl hszv ylwyvkbjlk pu aolpy lehja vypnpuhs mvyt, hjjvtwhuplk if lunspzo clyzpvuz myvt aol 1914 ayhuzshapvu if o.yhjroht.";

    // counts every occurance of letters (English alphabet) in given text
    int lettersCounter[ALPHABET_LETTERS_QUANTITY]{};
    char letters[ALPHABET_LETTERS_QUANTITY];
    /*
    * 'e' is the most common English letter (statistically)
    * 'e' index is 4
    */

    for (int i = 0; i < ALPHABET_LETTERS_QUANTITY; i++) {
        letters[i] = (char)(i + 97);
    }

    transform(text.begin(), text.end(), text.begin(), [](char c) { return tolower(c); });

    cout << endl << text << endl << endl;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' and text[i] <= 'z') {
            int index = (int)(text[i]) - 97;
            lettersCounter[index]++;

            //cout << text[i] << "[" << index << "]:" << lettersCounter[index] << "  ";
        }
    }

    //cout << endl << endl;

    for (int i = 0; i < ALPHABET_LETTERS_QUANTITY; i++) {
        cout << letters[i] << "[" << i << "]:" << lettersCounter[i] << endl;
    }

    bool isDecryptedProperly = false;
    while (!isDecryptedProperly) {
        int* it = max_element(lettersCounter, lettersCounter + ALPHABET_LETTERS_QUANTITY);
        int maxLetterIndex = (it - lettersCounter);
        cout << endl << letters[maxLetterIndex] << ": " << lettersCounter[maxLetterIndex] << endl << endl;
        lettersCounter[maxLetterIndex] = -1;

        int shift = maxLetterIndex - 4;
        if (shift < 0) shift = 26 - shift;

        string decrypted = decryptCeasarsCode(text, shift);

        cout << "shift: " << shift;

        cout << endl << decrypted << endl << endl;

        
        cout << "Is the message decrypted properly (1/0): ";
        cin >> isDecryptedProperly;
    }  
}