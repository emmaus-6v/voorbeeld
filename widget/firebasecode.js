import { initializeApp } from "https://www.gstatic.com/firebasejs/9.1.1/firebase-app.js";
import { getAuth, onAuthStateChanged, signInAnonymously } from "https://www.gstatic.com/firebasejs/9.1.1/firebase-auth.js";
import { getDatabase, ref, set, onValue, child, get, push, update } from "firebase/database } from "https://www.gstatic.com/firebasejs/9.1.1/firebase-database.js"

let userID;
let teamNaam = "testTeam";
let lastStartedGameRef;

const firebaseConfig = {
  apiKey: "AIzaSyCEL3ChZN08jy-auqwoVigd0yRWiy6q7Ns",
  authDomain: "kbaan-3c854.firebaseapp.com",
  databaseURL: "https://kbaan-3c854-default-rtdb.europe-west1.firebasedatabase.app",
  projectId: "kbaan-3c854",
  storageBucket: "kbaan-3c854.appspot.com",
  messagingSenderId: "681117185884",
  appId: "1:681117185884:web:760f98044ba88c1841f399"
};

const app = initializeApp(firebaseConfig);
const db = getFirestore(app);

const auth = getAuth();
signInAnonymously(auth)
  .then(() => {
    console.log("just signed in");
  })
  .catch((error) => {
    const errorCode = error.code;
    const errorMessage = error.message;
    console.log(errorMessage)
  });

const authentication = getAuth();
onAuthStateChanged(authentication, (user) => {
  if (user) {
    // User is signed in, see docs for a list of available properties
    // https://firebase.google.com/docs/reference/js/auth.user
    userID = user.uid;
    console.log("user id = " + userID)
  } else {
    console.log("just signed out")
  }
});

export function testWrite(getal) {
  const db = getDatabase();
  update(ref(db, 'teams/' + teamNaam), {
    getal: getal
  });
}
