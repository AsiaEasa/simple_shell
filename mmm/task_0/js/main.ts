interface Student {
    firstName: string;
    lastName: string;
    age: number;
    location: string;
}

const St1: Student = {
    firstName: "Asia",
    lastName: "Easa",
    age: 23,
    location: "Sudan"
};

const St2: Student = {
    firstName: "Ahmed",
    lastName: "Alamin",
    age: 23,
    location: "Sudan"
};

const Sl: Student[] = [St1, St2];

const Tc = document.getElementById('table-container');

function Rt(): void {
    const Tb = document.createElement('table');
    const TbBody = document.createElement('tbody');

    Sl.forEach((St) => {
        const Tr = document.createElement('tr');
        const Fn = document.createElement('td');
        const Lc = document.createElement('td');

        Fn.textContent = St.firstName;
        Lc.textContent = St.location;

        Tr.appendChild(Fn);
        Tr.appendChild(Lc);
        TbBody.appendChild(Tr);
    });

    Tb.appendChild(TbBody);

    if (Tc) {
        Tc.appendChild(Tb);
    }
}
