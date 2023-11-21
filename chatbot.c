//Projek gabut Daffabot
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define total_quest 27
#define total_answer 3

// Function to check for exact match
int isExactMatch(const char *input, const char *trigger) {
    return strcmp(input, trigger) == 0;
}

int tolower();

// Matriks trigger berisi pola-pola yang dapat menjadi input dari pengguna
const char* triggers[total_quest][total_answer] = {
    {"hai", "halo", "hello"},
    {"apa kabar", "bagaimana kabarmu", "apa kabarmu"},
    {"assalamualaikum", "assalamualaikum warahmatullahi wabarakatuh", "asalamulaikum"},
    {"how are you", "how is life", "how are things"},
    {"what are you doing", "what is going on", "what da dog doin"},
    {"sekarang kamu lagi apa", "lagi ngapain", "kamu lagi ngapain"},
    {"how old are you", "may i know your age", "your age"},
    {"berapa umur kamu", "berapa umurmu", "berapa usia kamu"},
    {"who are you", "are you human", "are you bot"},
    {"siapa kamu", "siapa dirimu", "siapa ini"},
    {"who created you", "who made you", "who your master"},
    {"siapa yang menciptakan kamu", "siapa yang menciptakanmu", "kamu dibuat siapa"},
    {"your name please", "your name", "may i know your name"},
    {"nama kamu siapa", "namamu siapa", "bolehkah aku mengetahui nama kamu"},
    {"i love you", "i like you", "i very love you"},
    {"aku mencintaimu", "aku mencintai kamu", "aku cinta kamu"},
    {"happy", "good", "fine"},
    {"baik", "senang", "bahagia"},
    {"bad", "bored", "tired"},
    {"help me", "tell me story", "tell me joke"},
    {"ah", "yes", "ok"},
    {"yo kawanku", "yo bro", "halo bang"},
    {"bye", "good bye", "goodbye"},
    {"buruk", "bosan", "lelah"},
    {"tolong saya", "ceritakan cerita", "ceritakan lelucon"},
    {"ya", "oke", "bagus"},
    {"selamat tinggal", "sampai jumpa", "sampai jumpa lagi"}
};

// Matriks responses berisi tanggapan-tanggapan yang sesuai dengan setiap trigger
const char* responses[total_quest][total_answer] = {
    {"hai juga", "halo!!", "yo.. whats up?!"},
    {"aku baik baik saja, bagaimana denganmu?", "alhamdulillah sehat", "saya baik, terima kasih!"},
    {"waalaikumsalam", "waalaikumsalam warahmatullahi wabarakatuh", "waalaikumsalam wr wb"},
    {"fine", "pretty well", "fantastic"},
    {"Nothing much", "About to go to sleep", "Can you guest?"},
    {"Lagi diam", "Nggak tau aku juga", "Mau tau banget atau mau tau doang?"},
    {"I am 1 day old", "im born yesterday", "idk"},
    {"Umurku baru 1 hari, karena baru diciptakan oleh Masterku", "gak tau"},
    {"I am just a bot", "I am a bot. What are you?", "fyi im a bot"},
    {"Aku hanyalah chatbot", "aku seorang reporter", "menurutmu apa"},
    {"Daffa Ahmad Ibrahim", "My Master", "Daffabot"},
    {"Oleh Daffa Ahmad Ibrahim", "Oleh Daffabot", "Oleh Masterku"},
    {"I am Anna the reporter", "I'm Anna", "My name is Anna"},
    {"Aku Anna si reporter", "Namaku Anna", "Namaku adalah Anna"},
    {"I love you too", "Me too", "I very love you too"},
    {"Aku juga mencintaimu sayang", "Aku juga menyukaimu", "Aku juga sangat mencintaimu"},
    {"Have you ever felt bad?", "Glad to hear it", "Mampus"},
    {"Apakah Kamu pernah merasa tidak enak?", "Senang mendengarnya", "MAMPUS!!"},
    {"Why?", "Why? You shouldn't!", "Try watching TV"},
    {"I will", "What about?", "Yeah... you know.."},
    {"Tell me a story", "Tell me a joke", "Tell me about yourself"},
    {"Apaan dih", "gaje", "anjing ga jelas"},
    {"Bye", "Goodbye", "See you later"},
    {"Mengapa?", "Mengapa? Seharusnya tidak!", "Cobalah menonton TV"},
    {"Ya, saya akan lakukan", "Bagaimana dengan itu?", "Mampus kau"},
    {"Ceritakan sebuah cerita", "Ceritakan lelucon", "Ceritakan tentang dirimu"},
    {"Sampai jumpa", "Selamat tinggal", "Sampai jumpa lagi"}
};

// Matriks alternativeResponses berisi tanggapan alternatif jika tidak ada trigger yang cocok
const char* alternativeResponses[total_answer] = {
    "maaf, bisa diulangi dengan jelas?",
    "aku tidak tahu apa maksudmu",
    "maaf, aku tidak mengerti"
};

// Fungsi getRandomResponse digunakan untuk mendapatkan tanggapan acak dari suatu kategori
const char* getRandomResponse(const char* responses[], int numResponses) {
    int randomIndex = rand() % numResponses;
    return responses[randomIndex];
}

// Fungsi cleanInput digunakan untuk membersihkan input dari user
void cleanInput(char* input) {
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    for (int i = 0; input[i]; i++) {
        if (input[i] == '?' || input[i] == '!') {
            input[i] = '\0';
        }
    }
}


// Fungsi output menghasilkan tanggapan berdasarkan input pengguna
void output(const char *input) {
    char cleanedInput[256];
    strcpy(cleanedInput, input);
    cleanInput(cleanedInput);

    char product[256];
    product[0] = '\0';
    int foundDaQuest = -1;

    // Pengecekan apakah input cocok dengan pola-pola yang ada
    for (int theColumn = 0; theColumn < total_quest; theColumn++) {
        for (int repeater = 0; repeater < total_answer; repeater++) {
            // Mengganti strstr dengan isExactMatch
            if (isExactMatch(cleanedInput, triggers[theColumn][repeater])) {
                foundDaQuest = theColumn;
                break;
            }
        }
        if (foundDaQuest >= 0) {
            break;
        }
    }

    // Jika ditemukan trigger yang cocok, ambil tanggapan dari matriks responses
    if (foundDaQuest >= 0) {
        strcpy(product, getRandomResponse(responses[foundDaQuest], total_answer));
    } else {
        // Jika tidak ada trigger yang cocok, ambil tanggapan alternatif
        strcpy(product, getRandomResponse(alternativeResponses, total_answer));
    }

    // Tampilkan hasil tanggapan ke layar
    printf("Chatbot: %s\n\n", product);
}

int main() {
    char input[256];
    
    srand(time(NULL));
    
    // Loop utama untuk interaksi dengan pengguna
    while (1) {
        printf("User: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';
        output(input);
    }
}
